rm(list=ls())

# read data
library(readxl)
library(forecast)

df_AUD = read_excel("AUD_15min.xlsx")
df_CAD = read_excel("CAD_15min.xlsx")
df_AAPL = read_excel("AAPL_15min.xlsx")

AUD_close = df_AUD$Close
CAD_close = df_CAD$Close
AAPL_close = df_AAPL$Close

#price series is not stationary take first difference and check
AUD_log = diff(log(AUD_close), lag = 1)
CAD_log = diff(log(CAD_close), lag = 1)
AAPL_log = diff(log(AAPL_close), lag = 1)

# leave 1 month of data for prediction and backtesting 2232 and 628
# use 1 month of data to train
l1 = 2232
l2 = 628
AUD_train = AUD_log[(length(AUD_log) - l1*2 + 1):(length(AUD_log) - l1)]
CAD_train = CAD_log[(length(CAD_log) - l1*2 + 1):(length(CAD_log) - l1)]
AAPL_train = AAPL_log[(length(AAPL_log) - l2*2 + 1):(length(AAPL_log) - l2)]

# check acf and pacf for arma p and q or use auto.arima
par(mfcol=c(2,1))
acf(AUD_train)
pacf(AUD_train)

acf(CAD_train)
pacf(CAD_train)

acf(AAPL_train)
pacf(AAPL_train)

#model selected by AIC
model_AUD = arima(AUD_train,order = c(2,0,2))
summary(model_AUD)
Box.test(model_AUD$residuals, type = "Ljung-Box")

model_CAD = arima(CAD_train, order = c(2,0,2)) 
summary(model_CAD)
Box.test(model_CAD$residuals, type = "Ljung-Box")

model_AAPL = arima(AAPL_train,order = c(2,0,2))
summary(model_AAPL)
Box.test(model_AAPL$residuals, type = "Ljung-Box")

#construct the predicted series using the testing set
# and then convert back to price
AUD_output = c()
AUD_pred = c()
for (i in 1:l1) {
  model = Arima(y = AUD_log[(length(AUD_close) - l1*2 + i):(length(AUD_close) - l1 + i - 1)],
                model = model_AUD)
  AUD_output[i] = predict(model)$pred[1]
  AUD_pred[i] = AUD_close[length(AUD_close) - l1 + i - 1] * exp(AUD_output[[i]])
}

CAD_output = c()
CAD_pred = c()
for (i in 1:l1) {
  model = Arima(y = CAD_log[(length(CAD_close) - l1*2 + i):(length(CAD_close) - l1 + i - 1)],
                model = model_CAD)
  CAD_output[i] = predict(model)$pred[1]
  CAD_pred[i] = CAD_close[length(CAD_close) - l1 + i - 1] * exp(CAD_output[i][1])
}

AAPL_output = c()
AAPL_pred = c()
for (i in 1:l2) {
  model = Arima(y = AAPL_log[(length(AAPL_close) - l2*2 + i):(length(AAPL_close) - l2 + i - 1)],
                model = model_AAPL)
  AAPL_output[i] = predict(model)$pred[1]
  AAPL_pred[i] = AAPL_close[length(AAPL_close) - l2 + i - 1] * exp(AAPL_output[i][1])
}

write.csv(AUD_pred, file = "AUD_arima.csv")
write.csv(CAD_pred, file = "CAD_arima.csv")
write.csv(AAPL_pred, file = "AAPL_arima.csv")


