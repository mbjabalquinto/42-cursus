
### Tabla Maestra de Comandos (Bash y SQL)

| Orden | Comando | Contexto / Acción | Fuente |
| :--- | :--- | :--- | :--- |
| **1** | `su` | Acceder a root para iniciar la instalación. | |
| **2** | `apt install sudo` | Instalar el paquete sudo. | |
| **3** | `sudo reboot` | Reiniciar la máquina. | |
| **4** | `sudo -V` | Verificar versión y configuración de sudo. | |
| **5** | `sudo adduser login` | Crear usuario (si no existe). | |
| **6** | `sudo addgroup user42` | Crear grupo `user42`. | |
| **7** | `getent group user42` | Verificar creación del grupo. | |
| **8** | `cat /etc/group` | Ver lista de grupos (alternativa). | |
| **9** | `sudo adduser user group` | Añadir usuario a un grupo (comando genérico). | |
| **10** | `nano /etc/group` | Verificar grupos editando fichero. | |
| **11** | `sudo apt update` | Actualizar repositorios. | |
| **12** | `sudo apt install openssh-server` | Instalar servidor SSH. | |
| **13** | `sudo service ssh status` | Verificar estado de SSH. | |
| **14** | `sudo nano /etc/ssh/sshd_config` | Configurar puerto 4242 y root login en servidor. | |
| **15** | `sudo nano /etc/ssh/ssh_config` | Configurar puerto 4242 en cliente. | |
| **16** | `sudo service ssh restart` | Reiniciar servicio SSH. | |
| **17** | `sudo apt install ufw` | Instalar Firewall UFW. | |
| **18** | `sudo ufw enable` | Activar UFW. | |
| **19** | `sudo ufw allow 4242` | Permitir puerto 4242. | |
| **20** | `sudo ufw status` | Ver estado del firewall. | |
| **21** | `touch /etc/sudoers.d/sudo_config` | Crear archivo de configuración sudo. | |
| **22** | `mkdir /var/log/sudo` | Crear carpeta de logs para sudo. | |
| **23** | `nano /etc/sudoers.d/sudo_config` | Editar reglas de sudo (intentos, mensajes, paths). | |
| **24** | `nano /etc/login.defs` | Configurar expiración de contraseñas (días). | |
| **25** | `sudo apt install libpam-pwquality` | Instalar módulo de calidad de contraseñas. | |
| **26** | `nano /etc/pam.d/common-password` | Configurar complejidad (minlen, ucredit, etc.). | |
| **27** | `ssh gemartin@localhost -p 4242` | Conexión SSH desde el host (prueba). | |
| **--** | **CREACIÓN DEL SCRIPT (Bash)** | *Comandos usados dentro de monitoring.sh* | |
| **28** | `uname -a` | Mostrar arquitectura. | |
| **29** | `grep "physical id" /proc/cpuinfo \| wc -l` | Contar CPUs físicas. | |
| **30** | `grep processor /proc/cpuinfo \| wc -l` | Contar CPUs virtuales. | |
| **31** | `free --mega` | Ver memoria RAM. | |
| **32** | `free --mega \| awk ...` | Filtrar RAM usada/total/porcentaje. |, |
| **33** | `df -m \| grep "/dev/" ...` | Calcular uso de disco (excluyendo boot). | |
| **34** | `vmstat 1 4 \| tail -1 ...` | Calcular carga de CPU. | |
| **35** | `who -b` | Ver fecha de último inicio. | |
| **36** | `lsblk \| grep "lvm"` | Verificar si LVM está activo. | |
| **37** | `ss -ta \| grep ESTAB` | Contar conexiones TCP establecidas. | |
| **38** | `users \| wc -w` | Contar usuarios activos. | |
| **39** | `hostname -I` | Obtener IP. | |
| **40** | `ip link \| grep "link/ether"` | Obtener MAC. | |
| **41** | `journalctl _COMM=sudo ...` | Contar comandos sudo ejecutados. | |
| **--** | **FIN DEL SCRIPT** | | |
| **42** | `sudo crontab -u root -e` | Editar cron para programar el script (10 min). | |
| **43** | `shasum nombremaquina.vdi` | Generar firma del disco virtual (desde Host). | |
| **--** | **BONUS: WEB & BASE DE DATOS** | | |
| **44** | `sudo apt install lighttpd` | Instalar servidor web Lighttpd. | |
| **45** | `sudo ufw allow 80` | Abrir puerto 80. | |
| **46** | `sudo apt install wget zip` | Instalar herramientas zip/wget. | |
| **47** | `cd /var/www/` | Ir a carpeta web. | |
| **48** | `sudo wget https://es.wordpress.org/...` | Descargar Wordpress. | |
| **49** | `sudo unzip latest-es_ES.zip` | Descomprimir Wordpress. | |
| **50** | `sudo mv html/ html_old/` | Mover html actual. | |
| **51** | `sudo mv wordpress/ html` | Renombrar carpeta wordpress a html. | |
| **52** | `sudo chmod -R 755 html` | Dar permisos a la carpeta. | |
| **53** | `sudo apt install mariadb-server` | Instalar MariaDB. | |
| **54** | `sudo mysql_secure_installation` | Script de seguridad MariaDB (wizard). | |
| **--** | **BONUS: SQL (Dentro de MariaDB)** | *Ejecutados tras entrar en la consola SQL* | |
| **55** | `CREATE DATABASE wp_database;` | Crear base de datos para Wordpress. | |
| **56** | `SHOW DATABASES;` | Verificar creación de la DB. | |
| **57** | `CREATE USER 'user'@'localhost' IDENTIFIED BY 'pass';`| Crear usuario (ej: 'gemartin', '12345'). | |
| **58** | `GRANT ALL PRIVILEGES ON wp_database.* ...;` | Dar permisos al usuario sobre la DB. | |
| **59** | `FLUSH PRIVILEGES;` | Recargar tabla de permisos. | |
| **--** | **BONUS: PHP & CONFIG** | *Vuelta a Bash* | |
| **60** | `sudo apt install php-cgi php-mysql` | Instalar PHP. | |
| **61** | `cd /var/www/html` | Ir a carpeta html. | |
| **62** | `nano wp-config.php` | Editar configuración Wordpress (con datos SQL). | |
| **63** | `sudo lighty-enable-mod fastcgi` | Habilitar FastCGI. | |
| **64** | `sudo lighty-enable-mod fastcgi-php` | Habilitar PHP para FastCGI. | |
| **65** | `sudo service lighttpd force-reload` | Recargar servidor web. | |
| **66** | `wget ... enable_lst_debian_repo.sh` | Descargar script repo LiteSpeed. | |
| **67** | `sudo apt install openlitespeed` | Instalar OpenLiteSpeed. | |
| **68** | `sudo /usr/local/lsws/.../admpass.sh` | Configurar password admin LiteSpeed. | |
| **69** | `sudo ufw allow 8088/tcp` | Permitir puerto LiteSpeed. | |
| **70** | `sudo ufw allow 7080/tcp` | Permitir puerto panel LiteSpeed. | |
| **71** | `sudo ufw reload` | Recargar firewall. | |
| **--** | **EVALUACIÓN (DEFENSA)** | | |
| **72** | `ls /usr/bin/*session` | Verificar que no hay interfaz gráfica. | |
| **73** | `sudo ufw status` | Verificar UFW. | |
| **74** | `sudo service ssh status` | Verificar SSH. | |
| **75** | `uname -v` | Verificar versión del kernel/OS. | |
| **76** | `getent group sudo` | Ver usuarios en grupo sudo. | |
| **77** | `sudo adduser name_user` | Crear usuario nuevo para test. | |
| **78** | `sudo addgroup evaluating` | Crear grupo de evaluación. | |
| **79** | `sudo adduser name_user evaluating` | Añadir usuario test al grupo. | |
| **80** | `sudo nano /etc/hostname` | Cambiar nombre de host. | |
| **81** | `sudo nano /etc/hosts` | Cambiar hosts (para el nuevo nombre). | |
| **82** | `lsblk` | **Verificar particiones**. | |
| **83** | `dpkg -s sudo` | Verificar instalación de sudo. | |
| **84** | `sudo adduser name_user sudo` | Añadir usuario test a sudo. | |
| **85** | `sudo ufw status numbered` | Ver reglas UFW numeradas. | |
| **86** | `sudo ufw allow 8080` | Abrir puerto 8080 (prueba). | |
| **87** | `sudo ufw delete num_rule` | Borrar regla de prueba. | |
| **88** | `which ssh` | Verificar ruta binario SSH. | |
| **89** | `ssh newuser@localhost -p 4242` | Conectar SSH con usuario nuevo. | |
| **90** | `sudo /etc/init.d/cron stop` | Parar servicio cron (monitoring). | |
