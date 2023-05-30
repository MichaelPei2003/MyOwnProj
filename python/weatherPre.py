import pandas as pd
from datetime import datetime, timedelta
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error



# Step 2: Preprocess the data
data = pd.read_csv(r"C:\Users\19832\Downloads\weather.csv", sep=";", skiprows=6)
data.columns = data.columns.str.strip()
print(data.columns)
data["Local time"] = pd.to_datetime(data["Local time"], format="%d.%m.%Y %H:%M")

# Filter out the data for 5 PM only
data = data[data["Local time"].dt.hour == 17]

# Fill missing values with the mean of the column
data.fillna(data.mean(), inplace=True)

# Step 3: Train a machine learning model
X = data[["Year", "Month", "Day", "T", "P0", "P", "U"]].values
y = data["T"].values

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

model = LinearRegression()
model.fit(X_train, y_train)

y_pred = model.predict(X_test)

mse = mean_squared_error(y_test, y_pred)
print("Mean Squared Error:", mse)

# Step 4: Predict the temperature on 2023-06-12 17:00
target_date = datetime(2023, 6, 12, 17, 0)
row = data.loc[data["Local time"] == target_date]

if row.empty:
    input_data = [
        target_date.year,
        target_date.month,
        target_date.day,
        data["T"].mean(),
        data["P0"].mean(),
        data["P"].mean(),
        data["U"].mean(),
    ]
    prediction = model.predict([input_data])[0]
    print(f"Predicted temperature at 2 meters above ground on 2023-06-12 17:00: {prediction:.2f}°C")
else:
    actual_temp = row["T"].values[0]
    print(f"Actual temperature at 2 meters above ground on 2023-06-12 17:00: {actual_temp:.2f}°C")