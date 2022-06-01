# conf2c
A C program to convert .config to a C header file.

## What does conf2c do?
conf2c converts .config to a C header file. See the example below.<br/><br/>
If the file `.config` has:<br/>
```
 CONFIG_DEVFS=n
 CONFIG_PROCFS=y
 CONFIG_SYSFS=y
```
conf2c will create `config.h` with the following content:</br>
```
 #ifndef _CONFIG_H
 #define _CONFIG_H
 
 #define CONFIG_DEVFS    'n'
 #define CONFIG_PROCFS    'y'
 #define CONFIG_SYSFS    'y'
 
 #endif //_CONFIG_H
```


## Installation
To install conf2c, run:
```bash
git clone https://github.com/kushagra765/conf2c
cd conf2c
make && make install
```
