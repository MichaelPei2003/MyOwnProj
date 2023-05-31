import pandas as pd
from datetime import datetime, timedelta
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
from sklearn.impute import SimpleImputer
from sklearn.ensemble import RandomForestRegressor

data = pd.read_csv(r"C:\Users\Michael\Downloads\weather.csv", sep=";", quotechar='"',index_col=False, parse_dates=['Local time'])


#data["Local time"] = pd.to_datetime(data["Local time"], format="%d.%m.%Y %H:%M")
data["Local time"] = pd.to_datetime(data["Local time"], infer_datetime_format=True)

#extract date info from Local time
data["date"] = pd.to_datetime(data["Local time"], format="%d.%m.%Y %H:%M")
data["Year"] = data["date"].dt.year
data["Month"] = data["date"].dt.month
data["Day"] = data["date"].dt.day
data["Hour"] = data["date"].dt.hour

# Fill NaN & split data into training and testing sets
imputer = SimpleImputer(strategy='mean')
X = imputer.fit_transform(data[["Year", "Month", "Day", "Hour"]].values)
y = imputer.fit_transform(data[["T"]].values)
X_train, X_test, y_train, y_test = train_test_split(X, y, train_size=0.9, test_size = 0.1, random_state=42)


# Train a linearregression model
model = RandomForestRegressor()
model.fit(X_train, y_train)


target_date = datetime(2023, 6, 12, 17)
target_year = target_date.year
target_month = target_date.month
target_day = target_date.day
target_hour = target_date.hour
input = pd.DataFrame({"Year":[target_year], "Month":[target_month], "Day":[target_day], "Hour":[target_hour]})
predicted_temp = model.predict(input)

print(f"Predicted temperature at 2 meters above ground on {target_date}: {float(predicted_temp):.2f}°C")