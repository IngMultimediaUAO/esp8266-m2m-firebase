Conectando esp8266 con firebase
================
Proyecto para conectar dos módulos esp8266 a firebase y lograr que ambos módulos se comuniquen entre ellos, haciendo que un módulo "A" apague o encienda el led que estará conectado al otro módulo "B", y viceversa, que el módulo "B" encienda o apague el led conectado al módulo "A".

Desarrollado por:

Andrés Doncel
Juan David Orejuela Bolaños

## Video del funcionamiento del proyecto

https://www.youtube.com/watch?v=ubFSNkUx46E 

## Esquema de funcionamiento y flujo de información en el proyecto

![Conexiones entre esp8266 y convertidor usb-serial](https://raw.githubusercontent.com/orejuelajd/esp8266-m2m-firebase/master/general-resources/flujo-info-parcial2.jpg)

## Objetivos:

* Crear una base de datos en firebase.
* Actualizar datos en la base de datos en firebase desde ambos esp8266. 
* Lograr que ambos módulos esp8266 puedan realizar consultas a la base de datos.

## Preparando la base de datos (Firebase)

**1)** Se debe crear el proyecto desde la consola de firebase en https://console.firebase.google.com/. Para este caso, el nombre del proyecto es example, por lo tanto la URL del proyecto es https://example.firebaseio.com/

**2)** Ya creado el repositorio, se deben cambiar los permisos para que cualquier persona pueda enviar datos a la database de firebase. En la consola del proyecto se debe ir a reglas y cambiar dichas reglas a las siguientes (conservando el formato JSON). Esto se hace ya que es solo una prueba pero se debe tener precaución pues estamos quitando cualquier seguridad:

`{
  "rules": {
    ".read": true,
    ".write": true
  }
}`

## Fuentes:

* Repositorio sobre esp8266: https://github.com/esp8266/Arduino/blob/master/doc/reference.md#digital-io
* Librería de Firebase para Arduino: https://github.com/googlesamples/firebase-arduino
* Como crear la base de datos en firebase: https://www.youtube.com/watch?v=bWH2Wc_p4HU
* Más información del Rest API con Curl de Firebase: https://www.firebase.com/docs/rest/api/  
* Arduino Yun + Curl + Firebase, primeros pasos: http://www.fabiobiondi.com/blog/2014/02/arduino-yun-angularjs-and-firebase-with-curl-realtime-data/
* Ejemplo básico para conexión de esp8266 con firebase: https://github.com/googlesamples/firebase-arduino/tree/master/examples/FirebaseDemo_ESP8266 
