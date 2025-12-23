*This project has been created as part of the 42 curriculum by mjabalqu.*

# Born2beroot

## Description
This project aims to introduce the fundamental concepts of system administration and virtualization. The goal is to create a virtual machine using specific strict rules, configuring the operating system, partitions, security policies, and user management.

## Instructions
1.  **Installation:** This project consists of a Virtual Machine image (`.vdi` or `.iso` with configuration).
2.  **Usage:** Open VirtualBox, import the machine or create a new one using the provided disk signature.
3.  **Login:** Connect via SSH on port 4242 or directly in the VM terminal.

## Design Choices & Comparisons

### Operating System: Debian vs Rocky
I have chosen **[Debian / Rocky]** for this project.
* **Debian:** [Escribe aquí 1 frase sobre por qué elegiste Debian. Ej: Es más estable y fácil para principiantes, usa `apt` y tiene una gran comunidad].
* **Rocky Linux:** It is a downstream binary compatible with RHEL (Red Hat Enterprise Linux). It uses `dnf`/`yum` and is more complex regarding SELinux configuration.
* **Choice Justification:** [Tu razón. Ej: Preferí Debian por la recomendación del subject para principiantes].

### Security: AppArmor vs SELinux
* **AppArmor (Debian):** It is a Linux kernel security module that allows the system administrator to restrict programs' capabilities with per-program profiles. It is path-based and generally considered easier to configure.
* **SELinux (Rocky):** Security-Enhanced Linux is a security architecture for Linux systems that allows administrators to have more control over who can access the system. It uses a labeling system (inode-based) and is more complex/strict.

### Firewall: UFW vs Firewalld
* **UFW (Uncomplicated Firewall):** It is a frontend for `iptables` designed to be easy to use. It is the default in Debian/Ubuntu.
* **Firewalld:** It provides a dynamically managed firewall with support for network/firewall zones. It is the default in RHEL/Rocky.

### Virtualization: VirtualBox vs UTM
* **VirtualBox:** It is a free and open-source hosted hypervisor for x86 virtualization. It is widely used and mandatory for this project (unless on Apple Silicon).
* **UTM:** It is a virtualization software for macOS (specifically optimized for Apple Silicon M1/M2/M3 chips) that uses QEMU under the hood.

## Resources & AI Usage
* **Resources:**
    * 42 Subject "Born2beroot".
    * Official Debian Documentation.
    * Man pages (`man sudo`, `man ufw`, etc.).

* **AI Usage:**
    * **Tools used:** Gemini.
    * **Context:** I used AI as a "thought partner" to understand the concepts of LVM partitioning, the difference between TTY and PTY, and to clarify the syntax of the bash script commands (`awk`, `grep`).
    * **Disclaimer:** No code was directly copy-pasted without understanding; the AI was used to explain the logic behind the commands.
