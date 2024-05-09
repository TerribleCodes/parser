FROM gcc:latest

WORKDIR /usr/src/app

COPY . .

RUN gcc -o parser parser.c

CMD ["./parser"]
