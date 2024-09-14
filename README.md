# Microwave-oven-timer-using-8051-Microcontroller

# Overview

This project implements a typical Microwave oven timer using an 8051 microcontroller, a 16x2 LCD (Hitachi HD44780 driver), and a 4x4 keypad. The oven can be started, paused, and cleared using specific keypad inputs. A safety door switch ensures user safety by stopping the oven when the door is opened. A buzzer provides feedback for key presses, time-outs, and warnings. The power of the magnetron is controlled using an electromagnetic relay. The program is implemented using a finite state machine for efficient operation.

## Features

- Start, pause, and clear the timer using the keypad.
- Safety door switch stops the oven when the door is opened.
- Buzzer provides feedback for various events.
- Finite state machine implementation for efficient program flow.
- Electromagnetic relay controls the power of the magnetron.

## Getting Started

To get started with this project, follow these steps:

1. **Hardware Setup**: Connect the 8051 microcontroller, 16x2 LCD, 4x4 keypad, safety door switch, buzzer, and electromagnetic relay according to the circuit diagram provided.
2. **Software Setup**: Upload the provided code to the 8051 microcontroller using your preferred IDE or tool.
3. **Usage**: Use the keypad to enter the desired time for the oven. Press ON to start or pause the oven. Press = to clear the entered time. The buzzer will provide feedback for key presses and events.


## Contributing

Contributions to this project are welcome! Fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE). Feel free to use and modify the code as per the license terms.

## Acknowledgements

- Thanks to the 8051 microcontroller community for support and resources.
- Hat tip to [Hitachi](https://www.hitachi.com) for the LCD driver.
- Special thanks to contributors and open-source libraries used in this project.

