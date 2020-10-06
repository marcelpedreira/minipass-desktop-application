# MiniPass Desktop Application

Cross platform desktop application whose purpose is the supervision of a physical access control system. The system is made up of [door controllers](https://github.com/marcelpedreira/minipass-door-controller-firmware) and [input/output controllers](https://github.com/marcelpedreira/minipass-input-output-controller-firmware) connected in a bus-type network using Modbus RTU protocol for communication. The application or supervision system is the master of the network while the controllers are the slaves.

## Features

- User and access code management (Wiegand26 format).
- Controller management.
- Level access management.
- Door supervision.
- Input/Output management.
- Real time event notification.
- On demand event reports.

## Technologies

- Qt framework.
- C++ programming language.
- MySQL database.
- Libmodbus library.
