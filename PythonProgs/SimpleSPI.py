import spidev
import time
import os
import logging
import datetime
import struct

logging.basicConfig(filename='SPIlog.log',level=logging.DEBUG)
logging.info(str(datetime.datetime.now()) + ': Starting SPI Datalogging.')

spi = spidev.SpiDev()
spi.open(0,0)

spi.max_speed_hz = 125000
spi.mode = 0b00

while True:
    resp = spi.readbytes(2)
    #print resp
    logging.info(str(datetime.datetime.now()) + ': SPI 16 Array =%s.' %resp)

    hi = resp[0]
    #print hi
    #logging.info(str(datetime.datetime.now()) + ': SPI 16 High =%s.' %resp[0])
    lo = resp[1]
    #print lo
    #logging.info(str(datetime.datetime.now()) + ': SPI 16 Low =%s.' %resp[1])

    actual = 256*hi + lo
    print actual
    logging.info(str(datetime.datetime.now()) + ': SPI Actual Value =%s.' %actual)

    time.sleep(0.1)


    resp = spi.readbytes(4)
    #print resp
    logging.info(str(datetime.datetime.now()) + ': SPI Float 32 Array =%s.' %resp)

    for i in range(len(resp)):
       # print resp[i]
        resp[i] = resp[i]-128
       # print "New adjusted value :%s." %resp[i]

    value = struct.unpack('<f', struct.pack('4b', *resp))[0]
    print value

    #value = struct.unpack('<f', resp)
    #print value
    time.sleep(0.1)
