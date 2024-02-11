FROM debian@sha256:36a9d3bcaaec706e27b973bb303018002633fd3be7c2ac367d174bafce52e84e
COPY . .
RUN apt update
RUN apt -y install coreutils=9.1-1
RUN apt -y install nasm=2.16.01-1
RUN apt -y install build-essential=12.9
CMD ["bash", "build.sh"]