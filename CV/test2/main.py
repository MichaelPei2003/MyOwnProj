# mnist
import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
from torchvision import datasets, transforms

import numpy as np

import matplotlib.pyplot as plt

# device
device = torch.device("cpu")
print("device", device)

# dataloader
train_loader = torch.utils.data.DataLoader(
    datasets.MNIST('data', train=True, download=True,
                   transform=transforms.Compose([
                       transforms.ToTensor(),
                       transforms.Normalize((0.1307,), (0.3081,))
                   ])),
    batch_size=64, shuffle=True)


# model
class Net(nn.Module):
    def __init__(self) -> None:
        super().__init__()
        self.fc1 = nn.Linear(784, 512)
        self.fc2 = nn.Linear(512, 512)
        self.fc3 = nn.Linear(512, 10)

    def forward(self, x):
        x = x.view(-1, 784)
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        x = self.fc3(x)
        return F.log_softmax(x, dim=1)


model = Net().to(device)

# optimizer
optimizer = optim.SGD(model.parameters(), lr=0.01, momentum=0.5)


# train
def train(epoch):
    model.train()
    for batch_idx, (data, target) in enumerate(train_loader):
        data, target = data.to(device), target.to(device)
        optimizer.zero_grad()
        output = model(data)
        loss = F.nll_loss(output, target)
        loss.backward()
        optimizer.step()
        if batch_idx % 100 == 0:
            print('Train Epoch: {} [{}/{} ({:.0f}%)]\tLoss: {:.6f}'.format(
                epoch, batch_idx * len(data), len(train_loader.dataset),
                       100. * batch_idx / len(train_loader), loss.item()))


for epoch in range(1, 2 + 1):
    train(epoch)


# test
def test():
    model.eval()
    test_loss = 0
    correct = 0
    with torch.no_grad():
        for _, (data, target) in enumerate(train_loader):
            data, target = data.to(device), target.to(device)
            output = model(data)
            test_loss += F.nll_loss(output, target, reduction='sum').item()  # sum up batch loss
            pred = output.argmax(dim=1, keepdim=True)  # get the index of the max log-probability
            correct += pred.eq(target.view_as(pred)).sum().item()

    test_loss /= len(train_loader.dataset)

    print('Test set: Average loss: {:.4f}, Accuracy: {}/{} ({:.0f}%)'.format(
        test_loss, correct, len(train_loader.dataset),
        100. * correct / len(train_loader.dataset)))


test()


# visualize
def visualize():
    # sample 4 images
    imgs = []
    preds = []
    label = []
    for _ in range(4):
        # visualize
        data, target = next(iter(train_loader))
        data, target = data.to(device), target.to(device)
        output = model(data)
        pred = output.argmax(dim=1, keepdim=True)
        pred = pred.cpu().numpy()
        target = target.cpu().numpy()
        data = data.cpu().numpy()
        # append
        imgs.append(data[0])
        preds.append(pred[0])
        label.append(target[0])
    # plot
    fig, axes = plt.subplots(1, 4, figsize=(10, 5))
    for i in range(4):
        axes[i].imshow(imgs[i][0], cmap='gray')
        axes[i].set_title('label: {}, pred: {}'.format(label[i], preds[i]))

    plt.show()


visualize()
