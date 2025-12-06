En este repostiorio se encuentran los archivos de matlab utilizados durante el desarrollo del proyecto.
En primer lugar se encuentran dos archivos .mlx los cuales se utilizaron para obtener los valores de la sintonización de los controladores tanto de actitud como de velocidad angular.

Los siguientes tres archivos .slx son los modelos Simulink utilizados tanto para las pruebas preliminares (interruptor.slx y pruebapulso.slx) como del controlador diseñado (ratetransition.slx).

# **Configuración de MATLAB**
Para poder ejecutar los modelos en pruebas HITL con el modo de conexión Monitor and Tune se requiere de la instalación de diversas extensiones de MATLAB ademas de su posterior configuración inicial.
1. El componente mas importante para ejecutar estos modelos es la instalación de la extension UAV Toolbox Support Package for PX4 Autopilots, esta extensión requiere de la instalación previa de de otras 5 extensiones listadas a continuación:
  - Simulink
  - Embedded Coder
  - MATLAB Coder
  - Simulink Coder
  - UAV Toolbox
2. Una vez instalada la extensión de MATLAB en el panel de add-ons abre administrar complementos, ubica UAV Toolbox Support Package for PX4 Autopilots y empieza la configuración inicial haciendo click en el boton **Setup**. Se abrira un panel de configuración en el cual el primer
paso que te pedira sera instalar Python 3.8.2. La ventana te dara dos opciones, el primer caso es si no tienes Python 3.8.2 selecciona "Automatically download and install", te pedira seleccionar la ubicación donde quieres que se instale tanto Python 3.8.2 como pySerial 3.4.
El segundo caso, es ya tener instalada la versión de Python requerida donde el te pedira seleccionar la ubicación donde se encuentra instalado para validarlo.
