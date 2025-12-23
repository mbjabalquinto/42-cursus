*This project has been created as part of the 42 curriculum by mjabalqu.*

# Born2beRoot

## Descripción

Born2beRoot es un proyecto del currículo de 42 cuyo objetivo es introducir al estudiante en la **administración de sistemas Linux**, centrándose en la instalación, configuración y securización de una máquina virtual.

Durante el proyecto se configura un sistema operativo Debian siguiendo estrictas políticas de seguridad, gestión de usuarios, firewall, servicios y particionado de discos.  
Además, se ha completado la **parte bonus**, que incluye la instalación de un sitio web funcional con WordPress y servicios adicionales.

## Sistema Operativo

### Elección: Debian GNU/Linux

Se ha elegido **Debian** como sistema operativo por las siguientes razones:

**Ventajas:**
- Gran estabilidad y fiabilidad
- Amplia documentación
- Gestión de paquetes sencilla mediante `apt`
- Ideal para servidores

**Desventajas:**
- Paquetes más conservadores (no siempre las versiones más recientes)
- Menos orientado al entorno empresarial que Rocky Linux

### Comparativa: Debian vs Rocky Linux

| Debian | Rocky Linux |
|------|-------------|
| Comunidad amplia | Orientado a entornos empresariales |
| Más flexible | Mayor integración con SELinux |
| Ideal para aprendizaje | Ideal para producción |

## Seguridad

### AppArmor vs SELinux

- **AppArmor (usado)**  
  - Más sencillo de configurar
  - Basado en perfiles
  - Ideal para proyectos educativos

- **SELinux**  
  - Más potente
  - Mayor complejidad
  - Usado en entornos empresariales

### Firewall: UFW vs firewalld

- **UFW (usado)**  
  - Configuración simple
  - Basado en iptables
  - Perfecto para servidores pequeños

- **firewalld**  
  - Más dinámico
  - Mayor complejidad
  - Integración avanzada con servicios

## Virtualización

### VirtualBox vs UTM

- **VirtualBox (usado)**  
  - Multiplataforma
  - Fácil de usar
  - Muy documentado

- **UTM**  
  - Optimizado para macOS (Apple Silicon)
  - Menos extendido en Linux/Windows

## Particionado del Disco (Bonus)

Se ha configurado un esquema de particiones personalizado para mejorar la seguridad y la organización del sistema:

- `/` (root)
- `/home`
- `/var`
- `/var/log`
- `/tmp`
- `/srv`
- `swap`

Este esquema permite:
- Aislar logs y datos del sistema
- Evitar que una partición llene todo el disco
- Mejorar la estabilidad y seguridad

## Gestión de Usuarios

- Usuario principal sin privilegios de root
- Uso de `sudo` para tareas administrativas
- Políticas de contraseñas estrictas
- Caducidad y complejidad configuradas

## Servicios Instalados

### Servicios Obligatorios
- SSH
- UFW
- AppArmor

### Servicios Bonus

#### WordPress (sitio web funcional)
- **Servidor web:** lighttpd  
- **Base de datos:** MariaDB  
- **Lenguaje:** PHP  

El sitio WordPress es accesible a través del navegador y totalmente funcional.

#### Servicio Extra: OpenLiteSpeed

Se ha instalado **OpenLiteSpeed** como servicio adicional a requerimento de la parte BONUS.

¿Qué aporta OpenLiteSpeed concretamente?

  1. Administración mediante interfaz web

      OpenLiteSpeed ofrece un panel de administración web que permite:
      - Gestión de virtual hosts
      - Logs
      - Configuración de PHP
      - Esto no lo ofrece Lighttpd por defecto

  2. Rendimiento y escalabilidad

      Diseñado para:
      - Alta concurrencia
      - Bajo consumo de recursos
      - Usado en entornos reales de producción

## Instrucciones

### Acceso a la máquina
ssh usuario@ip_maquina -p 4242
sudo systemctl status ufw
sudo systemctl status ssh
sudo systemctl status mariadb
Firewall
Los puertos abiertos han sido configurados según los servicios activos (SSH, HTTP, HTTPS, OpenLiteSpeed).

Recursos
Documentación y referencias
Documentación oficial de Debian

Manual de AppArmor

Guía oficial de UFW

WordPress Documentation

OpenLiteSpeed Documentation

Uso de Inteligencia Artificial
La inteligencia artificial se ha utilizado como herramienta de apoyo para:

Aclarar conceptos teóricos (Linux, seguridad, servicios)

Resolver dudas puntuales durante la configuración

Todas las decisiones finales, configuraciones y validaciones han sido realizadas manualmente por el autor del proyecto.

#### Estado del Proyecto<br>
✅ Parte obligatoria completada<br>
✅ Parte bonus completada<br>
✅ Sistema funcional y securizado<br>
