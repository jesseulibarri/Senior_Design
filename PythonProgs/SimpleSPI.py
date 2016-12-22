import spidev
import time
import os
import logging
import datetime
import struct

logging.basicConfig(filename='Speed_Test_IdentifierFirst_Nodelay_Test2.log',level=logging.DEBUG)
logging.info(str(datetime.datetime.now()) + ': Starting Speed Datalog.')

spi = spidev.SpiDev()
spi.open(0,0)

spi.max_speed_hz = 125000
spi.mode = 0b00

while True:

#   resp = spi.readbytes(2)
#   print resp
#   logging.info(str(datetime.datetime.now()) + ': SPI 16 Array =%s.' %resp)

#   hi = resp[0]
#   print hi
#   logging.info(str(datetime.datetime.now()) + ': SPI 16 High =%s.' %resp[0])
#   lo = resp[1]
#   print lo
#   logging.info(str(datetime.datetime.now()) + ': SPI 16 Low =%s.' %resp[1])

#   actual = 256*hi + lo
#   print actual
#   logging.info(str(datetime.datetime.now()) + ': SPI Actual Value =%s.' %actual)

#   time.sleep(0.1)

##################################################################################

    identifier = spi.readbytes(1)
    #print identifier

    if identifier[0] == 0xFF:

        resp = spi.readbytes(4)
        print resp

        Int_hi = resp[0]
        Int_lo = resp[1]
        Int_full = 256*Int_hi + Int_lo
        #print Int_full

        Dec_hi = resp[2]
        Dec_lo = resp[3]
        Dec_full = 256*Dec_hi + Dec_lo
        #print Dec_full

        logging.info(str(datetime.datetime.now()) + ': Integer Speed =%s.' %Int_full)
        logging.info(str(datetime.datetime.now()) + ': Decimal Speed =%s.' %Dec_full)
        #time.sleep(0.1)

        Int_full = float(Int_full)
        Dec_full = float(Dec_full)
        Dec_full = Dec_full / 1000
        ActualSpd = float(Dec_full + Int_full)

        print ActualSpd
        logging.info(str(datetime.datetime.now()) + ': Actual Speed =%s.' %ActualSpd)

####################################################################################


    identifier = spi.readbytes(1)
    #print identifier

    if identifier[0] == 0xEE:

        other = spi.readbytes(4)
        print other

        Int_hi = other[0]
        Int_lo = other[1]
        Int_full = 256*Int_hi + Int_lo
        #print Int_full

        Dec_hi = other[2]
        Dec_lo = other[3]
        Dec_full = 256*Dec_hi + Dec_lo
        #print Dec_full

        logging.info(str(datetime.datetime.now()) + ': Integer Other =%s.' %Int_full)
        logging.info(str(datetime.datetime.now()) + ': Decimal Other =%s.' %Dec_full)
        #time.sleep(0.1)

        Int_full = float(Int_full)
        Dec_full = float(Dec_full)
        Dec_full = Dec_full / 1000
        Actualother = float(Dec_full + Int_full)

        print Actualother
        logging.info(str(datetime.datetime.now()) + ': Actual Other =%s.' %Actualother)




###################################################################################
#
#
#
###################################################################################
    #resp = spi.readbytes(4)
    #print resp
    #logging.info(str(datetime.datetime.now()) + ': SPI Float 32 Array =%s.' %resp)

    #for i in range(len(resp)):
       # print resp[i]
       # resp[i] = resp[i]-128
       # print "New adjusted value :%s." %resp[i]

    #value = struct.unpack('<f', struct.pack('4b', *resp))[0]
    #print value

    #value = struct.unpack('<f', resp)
    #print value

##################################################################################

   # time.sleep(0.1)
