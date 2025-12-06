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
El siguiente paso es importante si por si quieres ejecutar una simulación SITL o HITL, ya que te pedira selecionar el autopiloto y su configuración a utilizar. Si quieres realizar pruebas SITL debes seleccionar el autopiloto PX4 Host Target y la configuración px4_sitl_default. Ahora si quierse ejecutar una prueba HITL debes seleccionar el autopiloto a utilizar en este caso Pixhawk 6C y la configuración en este caso para multicoptero, para esta instalación te pedira conexión serial en caso de utilizar un autopiloto real.
 > **NOTA:** Es de importante que cuando aparezca una ventana con una serie de 3 pasos seguirlos tal cual como se explica para que se instale el firmware en el autopiloto, estos son: Primero desconectar el USB luego apretar "ok" en la ventana y finalmente conectar nuevamente el USB.
  > 
<p align="center">
<img width="546" height="410" alt="image" src="https://github.com/user-attachments/assets/6a9a6c68-83d1-47e5-9888-9f0a2f37c1d5" />
</p>
En el siguiente paso selecciona usar el script de inicio por defecto y selecciona siguiente. Luego te pedira comprobar la instalación de QGroundControl, por lo que tendras que instalarlo si no lo tienes.  Con esto la extension UAV Toolbox Support Package for PX4 Autopilots ya estaria instalada, configurada y lista para utilizarse.

# **Configuración de modelos**
Los 3 modelos encontrados en este repositorio estan configurados para ser utilizados directamente con conexión serial para pruebas HITL, el unico parametro que probablemente se requiera cambiar es el valor del puerto COM que puede variar dependiendo del computador.

Ahora si quieres crear un modelo desde cero tanto para SITL o HITL solo hay que seguir los siguientes pasos.

1. Abrir Simulink y crear un modelo en blanco, una vez creado debes abrir la ventana "Model Settings" o "Model configuration parameters" que en su defecto puede abrirse con la combinación de teclas "CTRL+E".
   <p align="center">
   <img width="1035" height="456" alt="image" src="https://github.com/user-attachments/assets/4c85e640-de64-428f-b7da-5ac1b017ebad" />
   </p>
2. Una vez abierta la ventana en la seccion de "Hardware Implementation" deberemos seleccionar el autopiloto a utilizar, en caso de querer ejecutar pruebas SITL deberas seleccionar PX4 Host Target mientras que para pruebas HITL deberas seleccionar el autopiloto real que quieras conectar, en este caso seria el Pixhawk 6C.   
  > **NOTA:** Es importante que en los pasos de la configuración previa de la extensión haber seleccionado el par correspondiente de autopiloto y configuración para el tipo de prueba a realizar. Es decir si realizaste pruebas SITL (px4_sitl_default) y quieres ahora realizar HITL debes abrir nuevamente la configuración de la extensión validar todos los pasos e instalar la versión correspondiente del firmware en tu autopiloto.
  > 
   <p align="center">
   <img width="835" height="370" alt="image" src="https://github.com/user-attachments/assets/bc37880d-b21e-42f2-81eb-f8a8cd90d1c0" />
   </p>
3. Con esto se cargaran los parametros por defecto para cada configuración en el caso de que quieras realizar pruebas SITL no requieres modificar ningun valor. En cambio, si requieres ejecutar pruebas HITL debes ajustar o     comprobar (en caso de querer ejecutar mis modelos) los siguientes parametros:
En la misma ventana y sección previamente abierta hay un apartado llamado "Hardware board settings", la cual tiene otro apartado llamado "Target hardware resources" dentro de el debemos ir a "External mode", seleccionar la interfaz de comunicación "XCP on Serial", activar las 3 casillas disponibles y seleccionar para el puerto serial del autopiloto a utilizar. Si la conexión se realizara al puerto USB del autopiloto selecciona "/dev/ttyACM0", ahora en el caso de que quieras realizar la conexión serial con el puerto TELEM1 mediante FTDI selecciona "/dev/ttyS1/ y desactiva la casilla "Use the same host serail port for External mode as used form firmware upload (mentioned under 'build options')" y luego especifica el puerto COM de tu computador a utilizar.
<p align="center">
<img width="1053" height="718" alt="image" src="https://github.com/user-attachments/assets/5b5a0d88-8f91-47da-95ee-131443f2909c" />
</p>
4. En el apartado MAVLink hay una casilla llamada "Enable MAVLink on /dev/tty/ACM0" en caso de utilizar conexión serial con el puerto USB del autopiloto desactiva esta casilla, en cambio, si la conexión se realizara un puerto TELEM no es necesario desactivarla. Finalmente selecciona aplicar y puedes cerrar esta ventana ademas de seleccionar el modo de simulación en la pestaña Hardware de Simulink que en este caso se utilizo "Run on board".

<p align="center">
<img width="573" height="310" alt="image" src="https://github.com/user-attachments/assets/e03d3f4c-f29c-43ea-a5e2-38f379501aad" />
</p>

5.Para mejorar el "logging" de señales en modelos con sample rates altos dirigete a la pestaña Hardware de Simulink y abrie el "Control Panel".
<p align="center">
<img width="955" height="536" alt="image" src="https://github.com/user-attachments/assets/130bfb92-218c-417c-a362-a3d27327efec" />
</p>
Dentro en configuration selecciona la opcion "Signal & Triggering..." 

<p align="center">
<img width="385" height="451" alt="image" src="https://github.com/user-attachments/assets/5b9154d1-7d6a-4f79-86ff-cf6c1a1d94c4" />
</p>
Una vez dentro marca la casilla "Send multiple contiguous sample in same packet" luego selecciona aplicar y cierra las ventanas.

<p align="center">
<img width="743" height="582" alt="image" src="https://github.com/user-attachments/assets/2558a6a7-7cca-4440-914b-daf6bd562a68" />
</p>

Si seguiste todos estos pasos tu modelo estara listo para ser utilizado en pruebas HITL con la opción "Monitor and Tune" de Simulink, solo queda conectar el autopiloto mediante USB al computador ejecutar el modelo con "Monitor and Tune" el modelo empezara a codificarse en el lenguaje deseado y se instalara en el firmware del autopiloto, donde para que se ejecute la instalación volvera a aparecer la ventana con los 3 pasos mencionada previamente y es importante seguirla como se indica.

