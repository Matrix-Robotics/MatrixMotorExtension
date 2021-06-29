## Begin

Reset and initialize controller to default state.

```Arduino
bool begin()
```
### Return

- A **boolean** result of initialization. (`true` / `false`)
<br /><br /><br />
***
<br />

## Set PWM

8-bits pwm setting.

```Arduino
void setPWM(int ch, int speed)
```

### Parameters

- `ch` is a channel number from `1` through `4`
- `speed` is a pwm level from `-255` through `255`
<br /><br /><br />
***
<br />

## Get Battery Voltage

Get battery **voltage** of controller.

```Arduino
float getVbat()
```

### Return

- A **float** number from `0` through `8.4`. (unit: v)
