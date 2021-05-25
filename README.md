# Proyecto-Digitales-II




El contador de aforos es un dispositivo el cual permitirá el mejoramiento de los controles de aglomeraciones, dando señales de cuando el establecimiento llegue a ciertos porcentajes de ocupación, por ejemplo “Entrada permitida”  este mensaje responde cuando la capacidad del establecimiento está por debajo del 50% de ocupación, “Cuidado, capacidad supera la mitad” esto será lo que se mostrará en la LCD al superar el 50% de ocupación y por último “Prohibido, lugar lleno” cuando la capacidad de personas este 100% ocupada, cada porcentaje tendrá señales visuales aparte de la LCD, por ejemplo, se implementarán tres leds para esto, el primero será el led verde respondiendo simultáneamente con el primer mensaje que se planea mostrar, el segundo led que se implementa es un led naranja u amarillo para indicar que la capacidad esta resando el 50% de lo establecido, por ultimo se hace uso de un led rojo el cual indicará que la capacidad esta en su limite, ahora bien, tambien se piensa en la posibilidad de que alguien no respete este tipo de advertencias y queira entrar al establecimiento aun estando en su maxima capacidad, por lo tanto en el diseño se implemento el uso de un buzzer el cual emitirá ruido cuando el limite sea superado.

#  Sofware ustilizado 


www.microchip.com 


# Hardware-utilizado

El kit de evaluación Microchip PIC16F15244 Curiosity Nano es una plataforma de hardware para evaluar microcontroladores PIC. El kit de evaluación viene con un programador y depurador totalmente integrado que proporciona una integración perfecta con Microchip MPLAB X. El kit proporciona acceso a las funciones del PIC16F15244 permitiendo una fácil integración del dispositivo en un diseño personalizado. El kit presenta voltaje variable, un puerto serial virtual y una interfaz DGI para facilitar el desarrollo y la depuración.
![PIC](https://user-images.githubusercontent.com/79480593/119299015-cb8fac80-bc23-11eb-8a81-b36abfd5c73c.jpg)
![LCD](https://user-images.githubusercontent.com/79480593/119299024-d1858d80-bc23-11eb-8233-0b8a72778e9b.png)
https://www.microchip.com/Developmenttools/ProductDetails/EV09Z1.  

 
# Configuracion 


1. Conectar el PIC al pc usando un cable micro-USB.
2. Si aún no se ha intalado el sistema debe de desgargarlo para hacer buen uso de MPLAB (ultima versión)..
3. Instalar XC8 para correr el .X
![Diagrama en blanco (1)](https://user-images.githubusercontent.com/79480593/119440454-f6443880-bce9-11eb-89f8-6aff10bc2346.png)

Materiales:
Cable micro-USB.
Pantalla LCD 16x3.
Botón.
Potenciómetro.
Resistencias .
Led.
Buzzer.
Cable para conecciones.

# Uso
el dispositivo utiliza botones para registrar las personas que pasan por el establecimiento, cada persona que pase debe oprimir un boton ya sea cuando entre o sale, también el dueño de dicho establecimiento configura la capacidad máxima para el aforo

