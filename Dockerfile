#start from ubuntu latest
FROM ubuntu:latest
#download tools
RUN apt update -y
RUN apt upgrade -y
RUN apt install build-essential -y
#get mandelbrot source
RUN mkdir /opt/test
COPY * /opt/mandelbrot
#build mandelbrot
WORKDIR /opt/mandelbrot
RUN make
#default command
CMD [ "/bin/bash" ]