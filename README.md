<p align="center">
  <img src="/docs/logo.png"/>
</p>
RavenOS is a single-user and single-tasking operating system based on the monolithic kernel.

## Run Locally
For testing and development purposes, it is recommended to use a PC emulator, so you can run RavenOS in a window. Here are a few recommended emulators:
- [QEMU](https://www.qemu.org/)
- [VirtualBox](https://www.virtualbox.org/)

All you need to do is mount the RavenOS image, launch the emulator and select the appropriate boot device.

## Build
To build a RavenOS image using Docker, use these steps:

Clone the project
```
git clone https://github.com/Adiras/RavenOS.git
```

Go to the project directory
```
cd RavenOS
```

Build 'ravenos-build' image
```
docker build . -t ravenos-build
```

Run build.sh script inside Docker container.
```
docker run --rm -it -v ${PWD}:/usr/share/ravenos -w /usr/share/ravenos ravenos-build
```

This creates a `ravenos-i386.img` image in the `out` directory.
