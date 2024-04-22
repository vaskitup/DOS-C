# Script DOS-C 

Este script em C é projetado para fins educacionais, visando explorar o funcionamento dos sockets e a comunicação com servidores FTP. Ele funciona abrindo múltiplos sockets na máquina local e estabelecendo conexões com o servidor FTP de um alvo específico, passado como argumento para o script. O aspecto crítico a ser observado é que o script não encerra as conexões após o uso. Isso significa que, à medida que mais e mais conexões são abertas e mantidas ativas, o servidor alvo pode eventualmente tornar-se sobrecarregado, incapaz de lidar com o volume crescente de requisições. Esse cenário pode levar a um estado de negação de serviço (DoS), onde o servidor não consegue atender às solicitações legítimas de outros usuários, causando interrupções ou falhas em seus serviços.

## Instalação

Para usar este projeto, siga estas etapas:

```
git clone https://github.com/vaskitup/DOS-C.git
cd DOS-C
gcc DOS2.c -o dos
```

## Uso

Execute o seguinte comando para começar:

```
./dos <FTP_SERVER_IP>
```
