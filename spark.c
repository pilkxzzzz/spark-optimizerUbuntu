#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Розширені кольори та стилі
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define DIM     "\033[2m"
#define ITALIC  "\033[3m"
#define UNDERLINE "\033[4m"
#define BLINK   "\033[5m"
#define REVERSE "\033[7m"

// Яскраві кольори
#define BRIGHT_RED     "\033[91m"
#define BRIGHT_GREEN   "\033[92m"
#define BRIGHT_YELLOW  "\033[93m"
#define BRIGHT_BLUE    "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN    "\033[96m"
#define BRIGHT_WHITE   "\033[97m"

void clear_screen() {
    system("clear");
}

void show_fancy_loading_animation() {
    const char* frames[] = {
        "⠋", "⠙", "⠹", "⠸", "⠼", "⠴", "⠦", "⠧", "⠇", "⠏"
    };
    const int num_frames = 10;
    
    printf("\n");
    for (int i = 0; i < 20; i++) {
        printf("\r%s %s Завантаження... %s", 
               BRIGHT_CYAN,
               frames[i % num_frames],
               RESET);
        fflush(stdout);
        usleep(100000);
    }
    printf("\n");
}

void print_centered(const char* text, const char* color) {
    int width = 80;
    int padding = (width - strlen(text)) / 2;
    printf("%s%*s%s%*s%s\n", color, padding, "", text, padding, "", RESET);
}

void show_spark_logo() {
    clear_screen();
    printf("\n\n");
    print_centered("╔════════════════════════════════════════╗", BRIGHT_CYAN);
    print_centered("║            SPARK OPTIMIZER             ║", BRIGHT_CYAN);
    print_centered("╚════════════════════════════════════════╝", BRIGHT_CYAN);
    printf("\n");
    print_centered("⚡ Зроби свою Ubuntu швидшою! ⚡", BRIGHT_YELLOW);
    printf("\n");
    print_centered("Версія 2.0 | Розроблено з ❤️  by Pilk", BRIGHT_MAGENTA);
    printf("\n\n");
}

void print_separator() {
    printf("\n%s", BRIGHT_CYAN);
    for(int i = 0; i < 80; i++) printf("═");
    printf("%s\n\n", RESET);
}

void show_success_message(const char* message) {
    printf("\n%s%s ✓ %s%s\n", BRIGHT_GREEN, BOLD, message, RESET);
}

void show_error_message(const char* message) {
    printf("\n%s%s ✗ %s%s\n", BRIGHT_RED, BOLD, message, RESET);
}

void show_info_message(const char* message) {
    printf("\n%s%s ℹ %s%s\n", BRIGHT_BLUE, BOLD, message, RESET);
}

void optimize_gaming() {
    printf(YELLOW "\nІнформація про оптимізацію для геймінгу:\n" RESET);
    printf("- Встановлення GameMode від Feral Interactive\n");
    printf("- Оптимізація графічного стека\n");
    printf("- Налаштування параметрів WINE\n");
    printf("- Встановлення Steam і Lutris\n");
    printf(RED "\nБажаєте продовжити? (y/n): " RESET);
    
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        show_fancy_loading_animation();
        printf(GREEN "Оптимізація для геймінгу...\n" RESET);
        system("sudo add-apt-repository ppa:lutris-team/lutris -y");
        system("sudo apt update");
        system("sudo apt install gamemode steam lutris -y");
        system("sudo apt install wine-stable winetricks -y");
    }
}

void optimize_security() {
    printf(YELLOW "\nІнформація про оптимізацію безпеки:\n" RESET);
    printf("- Встановлення UFW (фаєрвол)\n");
    printf("- Налаштування базових правил безпеки\n");
    printf("- Встановлення ClamAV антивірусу\n");
    printf("- Налаштування автоматичних оновлень безпеки\n");
    printf(RED "\nБажаєте продовжити? (y/n): " RESET);
    
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        show_fancy_loading_animation();
        printf(GREEN "Налаштування безпеки...\n" RESET);
        system("sudo apt install ufw clamav unattended-upgrades -y");
        system("sudo ufw enable");
        system("sudo ufw default deny incoming");
        system("sudo ufw default allow outgoing");
        system("sudo dpkg-reconfigure --priority=low unattended-upgrades");
    }
}

void optimize_battery() {
    printf(YELLOW "\nІнформація про оптимізацію батареї:\n" RESET);
    printf("- Встановлення розширених налаштувань TLP\n");
    printf("- Оптимізація споживання енергії\n");
    printf("- Налаштування яскравості екрану\n");
    printf("- Моніторинг стану батареї\n");
    printf(RED "\nБажаєте продовжити? (y/n): " RESET);
    
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        show_fancy_loading_animation();
        printf(GREEN "Оптимізація батареї...\n" RESET);
        system("sudo apt install tlp tlp-rdw powertop -y");
        system("sudo tlp start");
        system("sudo powertop --auto-tune");
    }
}

void optimize_graphics() {
    printf(YELLOW "\nІнформація про оптимізацію графіки:\n" RESET);
    printf("- Встановлення останніх драйверів GPU\n");
    printf("- Налаштування композитного менеджера\n");
    printf("- Оптимізація OpenGL і Vulkan\n");
    printf("- Налаштування VSYNC\n");
    printf(RED "\nБажаєте продовжити? (y/n): " RESET);
    
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        show_fancy_loading_animation();
        printf(GREEN "Оптимізація графічної підсистеми...\n" RESET);
        system("sudo ubuntu-drivers autoinstall");
        system("sudo apt install mesa-utils vulkan-tools -y");
        system("sudo apt install compton -y");
        system("echo 'vblank_mode=0' | sudo tee -a /etc/environment");
    }
}

void optimize_docker() {
    printf(YELLOW "\nІнформація про налаштування Docker:\n" RESET);
    printf("- Встановлення Docker і Docker Compose\n");
    printf("- Налаштування автозапуску\n");
    printf("- Оптимізація параметрів контейнерів\n");
    printf("- Налаштування мережі Docker\n");
    printf(RED "\nБажаєте продовжити? (y/n): " RESET);
    
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        show_fancy_loading_animation();
        printf(GREEN "Встановлення та налаштування Docker...\n" RESET);
        system("sudo apt install docker.io docker-compose -y");
        system("sudo systemctl enable docker");
        system("sudo systemctl start docker");
        system("sudo usermod -aG docker $USER");
        system("echo '{\"dns\": [\"8.8.8.8\", \"8.8.4.4\"], \"storage-driver\": \"overlay2\"}' | sudo tee /etc/docker/daemon.json");
    }
}

void optimize_development() {
    printf(YELLOW "\nІнформація про налаштування середовища розробки:\n" RESET);
    printf("- Встановлення компіляторів та інструментів розробки\n");
    printf("- Налаштування Git\n");
    printf("- Встановлення VSCode\n");
    printf("- Встановлення популярних мов програмування\n");
    printf(RED "\nБажаєте продовжити? (y/n): " RESET);
    
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        show_fancy_loading_animation();
        printf(GREEN "Налаштування середовища розробки...\n" RESET);
        system("sudo apt install build-essential git cmake python3-pip nodejs npm -y");
        system("sudo snap install --classic code");
        system("sudo apt install default-jdk -y");
        system("curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.0/install.sh | bash");
    }
}

void optimize_multimedia() {
    printf(YELLOW "\nІнформація про оптимізацію мультимедіа:\n" RESET);
    printf("- Встановлення кодеків та медіаплеєрів\n");
    printf("- Налаштування звукової підсистеми\n");
    printf("- Оптимізація відтворення відео\n");
    printf("- Встановлення інструментів обробки медіа\n");
    printf(RED "\nБажаєте продовжити? (y/n): " RESET);
    
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        show_fancy_loading_animation();
        printf(GREEN "Оптимізація мультимедіа...\n" RESET);
        system("sudo apt install ubuntu-restricted-extras -y");
        system("sudo apt install vlc kdenlive audacity obs-studio -y");
        system("sudo apt install pulseaudio-equalizer pavucontrol -y");
        system("sudo apt install ffmpeg -y");
    }
}

void backup_system() {
    printf(YELLOW "\nІнформація про створення резервної копії:\n" RESET);
    printf("- Створення копії важливих файлів\n");
    printf("- Збереження списку встановлених пакетів\n");
    printf("- Архівація налаштувань системи\n");
    printf("- Створення точки відновлення\n");
    printf(RED "\nБажаєте продовжити? (y/n): " RESET);
    
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        show_fancy_loading_animation();
        printf(GREEN "Створення резервної копії...\n" RESET);
        system("mkdir -p ~/backup");
        system("sudo apt install timeshift -y");
        system("dpkg --get-selections > ~/backup/packages.list");
        system("cp -r ~/.config ~/backup/");
        system("sudo timeshift --create --comments \"SPARK Backup\"");
    }
}

void optimize_privacy() {
    printf(YELLOW "\nІнформація про налаштування приватності:\n" RESET);
    printf("- Налаштування брандмауера UFW\n");
    printf("- Встановлення VPN-клієнта\n");
    printf("- Налаштування приватного DNS\n");
    printf("- Встановлення інструментів шифрування\n");
    printf("- Налаштування захисту від відстеження\n");
    printf(RED "\nБажаєте продовжити? (y/n): " RESET);
    
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        show_fancy_loading_animation();
        printf(GREEN "Налаштування приватності...\n" RESET);
        system("sudo apt install ufw openvpn network-manager-openvpn -y");
        system("sudo apt install dnscrypt-proxy -y");
        system("sudo apt install cryptsetup veracrypt -y");
        system("sudo apt install privacy-badger-firefox -y");
        system("echo 'nameserver 1.1.1.1' | sudo tee /etc/resolv.conf");
        system("sudo ufw enable");
    }
}

void optimize_workspace() {
    printf(YELLOW "\nІнформація про оптимізацію робочого простору:\n" RESET);
    printf("- Встановлення додаткових тем та іконок\n");
    printf("- Налаштування док-панелі\n");
    printf("- Встановлення віджетів та розширень\n");
    printf("- Налаштування гарячих клавіш\n");
    printf(RED "\nБажаєте продовжити? (y/n): " RESET);
    
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        show_fancy_loading_animation();
        printf(GREEN "Оптимізація робочого простору...\n" RESET);
        system("sudo apt install gnome-tweaks -y");
        system("sudo apt install plank -y");
        system("sudo apt install papirus-icon-theme -y");
        system("gsettings set org.gnome.desktop.interface gtk-theme 'Adwaita-dark'");
        system("gsettings set org.gnome.desktop.wm.preferences button-layout 'close,minimize,maximize:'");
    }
}

void optimize_laptop() {
    printf(YELLOW "\nІнформація про оптимізацію для ноутбука:\n" RESET);
    printf("- Налаштування енергозбереження\n");
    printf("- Оптимізація температурного режиму\n");
    printf("- Налаштування тачпаду\n");
    printf("- Оптимізація яскравості\n");
    printf(RED "\nБажаєте продовжити? (y/n): " RESET);
    
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        show_fancy_loading_animation();
        printf(GREEN "Оптимізація для ноутбука...\n" RESET);
        system("sudo apt install thermald -y");
        system("sudo apt install laptop-mode-tools -y");
        system("sudo apt install fusuma -y"); // Для жестів тачпаду
        system("sudo systemctl enable thermald");
        system("echo 'options i915 enable_rc6=1 enable_fbc=1 semaphores=1' | sudo tee /etc/modprobe.d/i915.conf");
    }
}

void install_productivity_tools() {
    printf(YELLOW "\nІнформація про встановлення інструментів продуктивності:\n" RESET);
    printf("- Календар і планувальник задач\n");
    printf("- Інструменти для нотаток\n");
    printf("- Офісні програми\n");
    printf("- Інструменти для роботи з PDF\n");
    printf(RED "\nБажаєте продовжити? (y/n): " RESET);
    
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        show_fancy_loading_animation();
        printf(GREEN "Встановлення інструментів продуктивності...\n" RESET);
        system("sudo apt install gnome-calendar -y");
        system("sudo apt install nixnote2 -y"); // Evernote клієнт
        system("sudo apt install libreoffice -y");
        system("sudo apt install pdfarranger -y");
        system("sudo snap install notion-snap");
    }
}

void system_maintenance() {
    printf(YELLOW "\nІнформація про обслуговування системи:\n" RESET);
    printf("- Перевірка диска на помилки\n");
    printf("- Очищення журналів системи\n");
    printf("- Оптимізація бази даних APT\n");
    printf("- Видалення старих ядер\n");
    printf(RED "\nБажаєте продовжити? (y/n): " RESET);
    
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        show_fancy_loading_animation();
        printf(GREEN "Виконання обслуговування системи...\n" RESET);
        system("sudo fsck -f /dev/sda1");
        system("sudo journalctl --vacuum-time=7d");
        system("sudo apt-get clean");
        system("sudo apt-get autoremove --purge");
        system("sudo update-grub");
    }
}

void optimize_network() {
    printf(YELLOW "\nІнформація про оптимізацію мережі:\n" RESET);
    printf("- Налаштування DNS серверів\n");
    printf("- Оптимізація TCP/IP стеку\n");
    printf("- Встановлення Network Manager інструментів\n");
    printf("- Налаштування IPv6\n");
    printf(RED "\nБажаєте продовжити? (y/n): " RESET);
    
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        show_fancy_loading_animation();
        printf(GREEN "Оптимізація мережі...\n" RESET);
        system("sudo apt install network-manager-openvpn-gnome resolvconf -y");
        system("echo 'nameserver 1.1.1.1\nnameserver 8.8.8.8' | sudo tee /etc/resolvconf/resolv.conf.d/head");
        system("sudo sysctl -w net.ipv4.tcp_fastopen=3");
        system("sudo sysctl -w net.ipv4.tcp_congestion_control=bbr");
    }
}

void optimize_storage() {
    printf(YELLOW "\nІнформація про оптимізацію сховища:\n" RESET);
    printf("- Налаштування TRIM для SSD\n");
    printf("- Оптимізація параметрів монтування\n");
    printf("- Налаштування swap\n");
    printf("- Очищення системи\n");
    printf(RED "\nБажаєте продовжити? (y/n): " RESET);
    
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        show_fancy_loading_animation();
        printf(GREEN "Оптимізація сховища...\n" RESET);
        system("sudo systemctl enable fstrim.timer");
        system("sudo fstrim -av");
        system("echo 'vm.swappiness=10' | sudo tee -a /etc/sysctl.d/99-sysctl.conf");
        system("sudo apt autoremove -y && sudo apt clean");
    }
}

void install_work_tools() {
    printf(YELLOW "\nІнформація про встановлення робочих інструментів:\n" RESET);
    printf("- Встановлення офісних програм\n");
    printf("- Інструменти для PDF\n");
    printf("- Програми для відеоконференцій\n");
    printf("- Менеджери завдань\n");
    printf(RED "\nБажаєте продовжити? (y/n): " RESET);
    
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        show_fancy_loading_animation();
        printf(GREEN "Встановлення робочих інструментів...\n" RESET);
        system("sudo apt install libreoffice -y");
        system("sudo snap install zoom-client");
        system("sudo apt install pdfarranger -y");
        system("sudo apt install planner -y");
    }
}

void optimize_virtualization() {
    printf(YELLOW "\nІнформація про оптимізацію віртуалізації:\n" RESET);
    printf("- Встановлення KVM\n");
    printf("- Налаштування VirtualBox\n");
    printf("- Оптимізація продуктивності VM\n");
    printf("- Налаштування мережевого мосту\n");
    printf(RED "\nБажаєте продовжити? (y/n): " RESET);
    
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        show_fancy_loading_animation();
        printf(GREEN "Налаштування віртуалізації...\n" RESET);
        system("sudo apt install qemu-kvm libvirt-daemon-system virtinst bridge-utils -y");
        system("sudo apt install virtualbox -y");
        system("sudo usermod -aG libvirt $USER");
        system("sudo usermod -aG kvm $USER");
    }
}

void modify_main() {
    show_spark_logo();
    print_separator();
    
    printf("%s%s МЕНЮ ОПТИМІЗАЦІЇ %s\n\n", BRIGHT_CYAN, BOLD, RESET);

    // Системні оптимізації
    printf("%s%s[A] Системні оптимізації%s\n", BRIGHT_YELLOW, BOLD, RESET);
    printf("  %s1%s. 🚀 Оптимізація системи\n", BRIGHT_GREEN, RESET);
    printf("  %s2%s. 🔒 Оптимізація безпеки\n", BRIGHT_GREEN, RESET);
    printf("  %s3%s. 🔋 Оптимізація батареї\n", BRIGHT_GREEN, RESET);
    printf("  %s4%s. 🖥️  Оптимізація графіки\n", BRIGHT_GREEN, RESET);
    
    // Розробка та віртуалізація
    printf("\n%s%s[B] Розробка та віртуалізація%s\n", BRIGHT_YELLOW, BOLD, RESET);
    printf("  %s5%s. 🐳 Налаштування Docker\n", BRIGHT_BLUE, RESET);
    printf("  %s6%s. 💻 Налаштування середовища розробки\n", BRIGHT_BLUE, RESET);
    printf("  %s7%s. 🎮 Оптимізація для геймінгу\n", BRIGHT_BLUE, RESET);
    printf("  %s8%s. 🔄 Оптимізація віртуалізації\n", BRIGHT_BLUE, RESET);
    
    // Мультимедіа та робочі інструменти
    printf("\n%s%s[C] Мультимедіа та інструменти%s\n", BRIGHT_YELLOW, BOLD, RESET);
    printf("  %s9%s. 🎵 Оптимізація мультимедіа\n", BRIGHT_MAGENTA, RESET);
    printf("  %s10%s. 📊 Встановлення робочих інструментів\n", BRIGHT_MAGENTA, RESET);
    printf("  %s11%s. 📝 Встановлення офісних програм\n", BRIGHT_MAGENTA, RESET);
    
    // Мережа та сховище
    printf("\n%s%s[D] Мережа та сховище%s\n", BRIGHT_YELLOW, BOLD, RESET);
    printf("  %s12%s. 🌐 Оптимізація мережі\n", BRIGHT_CYAN, RESET);
    printf("  %s13%s. 💾 Оптимізація сховища\n", BRIGHT_CYAN, RESET);
    printf("  %s14%s. 📦 Створення резервної копії\n", BRIGHT_CYAN, RESET);
    
    // Додаткові опції
    printf("\n%s%s[E] Додаткові опції%s\n", BRIGHT_YELLOW, BOLD, RESET);
    printf("  %s15%s. 🔐 Оптимізація конфіденційності\n", BRIGHT_RED, RESET);
    printf("  %s16%s. 🔧 Обслуговування системи\n", BRIGHT_RED, RESET);
    printf("  %s17%s. ⚡ Виконати всі оптимізації\n", BRIGHT_RED, RESET);
    
    printf("\n%s0%s. 👋 Вийти\n", BRIGHT_YELLOW, RESET);
    
    print_separator();
    printf("%s%sВведіть номер опції:%s ", BRIGHT_CYAN, BOLD, RESET);
}

int main() {
    int choice;
    do {
        modify_main();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                show_fancy_loading_animation();
                printf(GREEN "Оновлення системи...\n" RESET);
                system("sudo apt update");
                system("sudo apt upgrade -y");
                break;
            case 2:
                show_fancy_loading_animation();
                printf(GREEN "Очистка системи...\n" RESET);
                system("sudo apt autoremove -y");
                system("sudo apt clean");
                break;
            case 3:
                show_fancy_loading_animation();
                printf(GREEN "Оптимізація SWAP...\n" RESET);
                system("sudo swapoff -a");
                system("sudo mkswap /dev/nvme0n1p3");
                system("sudo swapon /dev/nvme0n1p3");
                break;
            case 4:
                show_fancy_loading_animation();
                printf(GREEN "Вимкнення непотрібних служб...\n" RESET);
                system("sudo systemctl stop bluetooth.service");
                system("sudo systemctl disable bluetooth.service");
                system("sudo systemctl stop cups.service");
                system("sudo systemctl disable cups.service");
                system("sudo systemctl stop avahi-daemon.service");
                system("sudo systemctl disable avahi-daemon.service");
                break;
            case 5:
                show_fancy_loading_animation();
                printf(GREEN "Оптимізація пам'яті...\n" RESET);
                system("sudo sysctl -w vm.swappiness=10");
                system("sudo sysctl -w vm.vfs_cache_pressure=50");
                break;
            case 6:
                show_fancy_loading_animation();
                printf(GREEN "Оптимізація мережі...\n" RESET);
                system("sudo sysctl -w net.ipv4.tcp_fastopen=3");
                system("sudo sysctl -w net.ipv4.tcp_congestion_control=bbr");
                break;
            case 7:
                show_fancy_loading_animation();
                printf(GREEN "Оптимізація SSD...\n" RESET);
                system("sudo trim -f -a");
                break;
            case 8:
                show_fancy_loading_animation();
                printf(GREEN "Оптимізація CPU...\n" RESET);
                system("sudo cpufreq-set -g performance");
                break;
            case 9:
                show_fancy_loading_animation();
                printf(GREEN "Встановлення корисніх інструментів...\n" RESET);
                system("sudo apt install htop iotop iftop -y");
                break;
            case 10:
                optimize_gaming();
                break;
            case 11:
                optimize_security();
                break;
            case 12:
                optimize_battery();
                break;
            case 13:
                optimize_graphics();
                break;
            case 14:
                optimize_docker();
                break;
            case 15:
                optimize_development();
                break;
            case 16:
                optimize_multimedia();
                break;
            case 17:
                backup_system();
                break;
            case 18:
                optimize_privacy();
                break;
            case 19:
                optimize_workspace();
                break;
            case 20:
                optimize_laptop();
                break;
            case 21:
                install_productivity_tools();
                break;
            case 22:
                system_maintenance();
                break;
            case 23:
                printf(RED "\nУВАГА: Буде виконано всі оптимізації послідовно!\n" RESET);
                printf(YELLOW "Бажаєте продовжити? (y/n): " RESET);
                char all_choice;
                scanf(" %c", &all_choice);
                if (all_choice == 'y' || all_choice == 'Y') {
                    show_fancy_loading_animation();
                    system("sudo apt update");
                    system("sudo apt upgrade -y");
                    system("sudo apt autoremove -y");
                    system("sudo apt clean");
                    system("sudo swapoff -a");
                    system("sudo mkswap /dev/nvme0n1p3");
                    system("sudo swapon /dev/nvme0n1p3");
                    system("sudo systemctl stop bluetooth.service");
                    system("sudo systemctl disable bluetooth.service");
                    system("sudo systemctl stop cups.service");
                    system("sudo systemctl disable cups.service");
                    system("sudo systemctl stop avahi-daemon.service");
                    system("sudo systemctl disable avahi-daemon.service");
                    system("sudo sysctl -w vm.swappiness=10");
                    system("sudo sysctl -w vm.vfs_cache_pressure=50");
                    system("sudo sysctl -w net.ipv4.tcp_fastopen=3");
                    system("sudo sysctl -w net.ipv4.tcp_congestion_control=bbr");
                    system("sudo trim -f -a");
                    system("sudo cpufreq-set -g performance");
                    optimize_graphics();
                    optimize_docker();
                    optimize_development();
                    optimize_multimedia();
                    backup_system();
                    optimize_privacy();
                    optimize_workspace();
                    optimize_laptop();
                    install_productivity_tools();
                    system_maintenance();
                }
                break;
            case 24:
                optimize_network();
                break;
            case 25:
                optimize_storage();
                break;
            case 26:
                install_work_tools();
                break;
            case 27:
                optimize_virtualization();
                break;
            case 0:
                printf(GREEN "\n👋 Дякуємо за використання SPARK! До зустрічі!\n" RESET);
                return 0;
            default:
                printf(RED "❌ Невірний вибір. Спробуйте ще раз.\n" RESET);
        }
        
        printf(YELLOW "\nНатисніть Enter для продовження..." RESET);
        getchar();
        getchar();
    } while (choice != 0);

    return 0;
}