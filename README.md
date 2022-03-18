# Elevador; Implementação e Testes
Modelagem do sistema de um elevador com:
<ul>
  <li>Seis Andares</li>
  <li>Dois botões de chamada em cada Andar</li>
  <li>Seis botões de andar destino no habitáculo</li>
  <li>Um botão de emergência</li>
  <li>Sensor de Andar</li>
  <li>Sensor de estado da porta</li>
  <li>Sensor de presença de usuário</li>
</ul>

# Participantes

Eryk Kooshin Suguiura (18201347) &
Vinícius Slovinski (18201356) &
Vitor José Duarte Quintans (18201357).

# Build
```sh
> cd build
> cmake ..
> cmake --build .
```

# Testes
## lcov
O software lcov foi utilizado para mensurar a cobertura de código, para executa-lo, execute os seguintes comandos no diretório raiz do projeto: 

```sh
> cd ./lcovdir
> lcov -c -d .. -o my.info
> genhtml -o results/ my.info 
```
Assim, os resultados do teste serão gravados no diretório 'results', nomeados como 'my.info'.

