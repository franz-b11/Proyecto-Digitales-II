# Proyecto-Digitales-II
The capacity counter is a device which will allow the improvement of crowd controls, giving signals when the establishment reaches certain percentages of occupancy, for example "Entry allowed" this message responds when the capacity of the establishment is below 50% occupancy, "Caution, capacity exceeds half" this will be what will be displayed on the LCD when exceeding 50% occupancy and finally "Prohibited, full place" when the capacity of people is 100% occupied, each percentage will have visual signals apart from the LCD, for example, three LEDs will be implemented for this, the first will be the green LED responding simultaneously with the first message that is planned to display, the second LED that is implemented is an orange or yellow LED to indicate that the capacity is subtracting 50% of the established, finally it makes use of a red LED which will indicate that the capacity is at its limit, now, it is also thought in the possibility that someone does not respect this type of warnings and wants to enter the establishment even being at its maximum capacity, therefore in the design was implemented the use of a buzzer which will emit noise when the limit is exceeded.



![PIC](https://user-images.githubusercontent.com/79480593/119299015-cb8fac80-bc23-11eb-8a81-b36abfd5c73c.jpg)
![LCD](https://user-images.githubusercontent.com/79480593/119299024-d1858d80-bc23-11eb-8233-0b8a72778e9b.png)

https://www.microchip.com/Developmenttools/ProductDetails/EV09Z1.  

 
# Configuracion 


1. Conectar el PIC al pc usando un cable micro-USB.
2. Si aún no se ha intalado el sistema debe de desgargarlo para hacer buen uso de MPLAB (ultima versión)..
3. Instalar XC8 para correr el .X
![Diagrama en blanco (1)](https://user-images.githubusercontent.com/79480593/119440454-f6443880-bce9-11eb-89f8-6aff10bc2346.png)


- Cable micro-USB.
- Pantalla LCD 16x3.
- Botón.
- Potenciómetro.
- Resistencias .
- Led.
- Buzzer.
- Cable para conecciones.

# Uso
el dispositivo utiliza botones para registrar las personas que pasan por el establecimiento, cada persona que pase debe oprimir un boton ya sea cuando entre o sale, también el dueño de dicho establecimiento configura la capacidad máxima para el aforo

