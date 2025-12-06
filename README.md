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
<p align="center">
<img width="681" height="514" alt="image" src="https://github.com/user-attachments/assets/4d0e039a-912d-44e0-8a61-ff89844b9a13" />
</p>
3. El siguiente paso es instalar un subsistema de Windows para Linux (WSL2). Para poder instalar un WSL2 se requiere tener activado en la BIOS del computador la virtualización usualmente referida como "Virtualization Technology", "Intel VT-x" o "AMD-V". Una vez activado en el buscador de windows escribe cmd para abrir el simbolo del sistema ejecutandolo como administrador, despues de abrirlo ejecuta el siguiente comando: 

```
wsl --install -d Ubuntu-22.04
```
Una vez instalado reincia el computador, abre nuevamente el simbolo del sistema y ejecuta el siguiente comando para seleccionar Ubuntu 22.04 como predeterminado
```
wsl --set-default Ubuntu-22.04
```
Con esto la WSL2 ya esta instalada ahora es necesario configurarla, para esto abre nuevamente el simbolo del sistema sin permisos de administrador y ejecuta el comando `wsl` para abrir la consola del WSL2 lo cual iniciara la instalación de Ubuntu 22.04. Una vez terminada la instalación la consola te pedira elegir un nombre de usuario y una contraseña. Una vez configurado ejecuta el comando `wsl --set-default Ubuntu` para elegir Ubuntu como la distribución predeterminada. Ahora para abrir la consola de la WSL2 solo necesitas escribir wsl en el buscador de windows.

4. Con la WSL2 instalada y configurada ahora se requiere descargar el codigo fuente de PX4 en este ambiente. Primero ejecuta la consola del WSL2, navega al directorio principal con el comando `cd ~` (Es crucial que el codigo se descarge en directorio principal). Ejecuta el comando 
```
git clone https://github.com/PX4/PX4-Autopilot.git --recursive
```
para empezar a descargar el codigo fuente de PX4, descarga que puede tomar unos minutos dependiendo de la conexión a internet. Una vez clonado el firmware ejecuta los siguientes comandos en la consola.
```
cd PX4-Autopilot
```
```
git checkout v1.14.3 -f
```
```
git submodule update --init --recursive
```
Luego comprobaremos que se clono la version necesaria del firmware (v1.14.3) para eso ejecutamos los siguientes comandos.
```
cd PX4-Autopilot
```
```
git describe --tags
```
Si la consola te devuelve "--tags is v1.14.3" quiere decir que se instalo la version correcta para la extensión de MATLAB.

Finalmente se requiere instalar un ambiente de desarrollo usado para desarrollar firmware para todas las placas de autopiloto Pixhawk.
En la consola de la WSL2 dirigete al directorio del firmware de PX4 y luego a la carpeta donde esta el scrit de instalación de la Toolchain con los codigos:
```
cd ~
```
```
cd PX4/PX4-Autopilot/
```
```
cd Tools/setup
```
Una vez en la carpeta ejecuta el script de instalación con el codigo: 
```
bash ./ubuntu.sh
```
Te pedira insertar tu contraseña previamente configurada y luego iniciara la instalación. Una vez terminado el proceso reinicia el ambiente WSL2.

Con ya se completaron la mayoria de los pasos de la extensión de MATLAB que requieren instalación externa, el siguiente paso que te pedira la ventana de configuración es si quieres desabilitar los controladores por defecto del firmware PX4, tanto si seleccionas la casilla como si la desmarcas estos controladores se terminaran reescribiendo por los modelos Simulink.
El siguiente paso es importante si por si quieres ejecutar una simulación SITL o HITL, ya que te pedira selecionar el autopiloto y su configuración a utilizar. Si quieres realizar pruebas SITL debes seleccionar el autopiloto PX4 Host Target y la configuración px4_sitl_default. Ahora si quierse ejecutar una prueba HITL debes seleccionar el autopiloto a utilizar en este caso Pixhawk 6C y la configuración en este caso para multicoptero.

<p align="center">
<img width="546" height="410" alt="image" src="https://github.com/user-attachments/assets/6a9a6c68-83d1-47e5-9888-9f0a2f37c1d5" />
</p>
En el siguiente paso selecciona usar el script de inicio por defecto y selecciona siguiente. Luego te pedira comprobar la instalación de QGroundControl, por lo que tendras que instalarlo si no lo tienes.
