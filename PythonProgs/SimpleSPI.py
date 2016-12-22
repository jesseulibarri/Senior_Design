import spidev
import time
import os
import logging
import datetime

logging.basicConfig(filename='SPIlog.log',level=logging.DEBUG)
logging.info(str(datetime.datetime.now()) + ': Starting SPI Datalogging.')

spi = spidev.SpiDev()
spi.open(0,0)

spi.max_speed_hz = 125000
spi.mode = 0b00

while True:
    resp = spi.readbytes(2)
    print resp
    logging.info(str(datetime.datetime.now()) + ': SPI 16 Array =%s.' %resp)

    hi = resp[0]
    print hi
    logging.info(str(datetime.datetime.now()) + ': SPI 16 High =%s.' %resp[0])
    lo = resp[1]
    print lo
    logging.info(str(datetime.datetime.now()) + ': SPI 16 Low =%s.' %resp[1])

    actual = 256*hi + lo
    print actual
    logging.info(str(datetime.datetime.now()) + ': SPI Actual Value =%s.' %actual)

    time.sleep(0.1)

