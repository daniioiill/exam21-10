# В качестве исходного образа взять ubuntu
FROM ubuntu:20.04

# Информация об авторе
LABEL author="Shabalin_Daniil_Aleksandrovich_231-3213"

# Установка необходимых пакетов
RUN apt-get update && \
    apt-get install -y gcc g++ make qt5-default qtbase5-dev && \
    apt-get clean

# Создаем директорию для проекта
WORKDIR /MyProj_231-3213_Shabalin

# Копируем файлы проекта в контейнер
COPY . .

# Сборка проекта
RUN qmake MyProgram.pro
RUN make

# Установка значения параметра программы по умолчанию
CMD ["./my_Program", "параметр"]
