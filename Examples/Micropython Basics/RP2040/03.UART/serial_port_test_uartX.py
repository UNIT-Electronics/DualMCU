#Programa para probar el puerto serial, conectar TXD->RxD por ejemplo, para el UART0 conectar GPIO(0) con GPIO(1)
#Adrián Rabadán O.
#28052023

from machine import UART, Pin
import time

# Configuración de la comunicación serial
port = 'UART0'  # Reemplaza 'COMX' con el puerto serial correspondiente (por ejemplo, 'COM1' en Windows o '/dev/ttyUSB0' en Linux)
baudrate = 115200  # Velocidad en baudios

# Crear instancia del objeto Serial
uart0 = UART(0, baudrate=115200, tx=Pin(0,Pin.OUT), rx=Pin(1,Pin.IN))

#rxData = bytes() #Define a reception variable
rxData = bytearray() #Define a reception variable

# Verificar si la comunicación serial está abierta
if uart0.init:
    print(f'Conexión serial establecida en el puerto {port}')

    # Leer datos del usuario y enviarlos al ESP32
    while True:
        data = input('Ingresa un mensaje: ')
        uart0.write(data.encode())  # Enviar datos al ESP32
        
        time.sleep(0.025)
        
        while uart0.any():
            rxData = uart0.readline()[0:]
            data_incomming=True
            
        if data_incomming==True:
            data_incomming=False
            print("Mensaje recibido: " + str(rxData).strip("b'"))
                        
        if data.lower() == 'exit':
            break

    # Cerrar la conexión serial
    uart0.flush
    uart0.deinit
    print('Conexión serial cerrada')
    
    
else:
    print(f'Error al abrir el puerto {port}')