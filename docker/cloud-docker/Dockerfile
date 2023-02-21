FROM alpine:latest

RUN apk update \
    && apk update

RUN apk add g++ cmake asio-dev

COPY . /wndtn

WORKDIR /wndtn

RUN cd /wndth && cmake . && make

CMD ["./app"]