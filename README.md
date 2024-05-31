

# C-entidade-professor


- Todo código deve possuir uma opção de digitar "/ajuda", onde ele vai descrever o que o código faz e como utilizar. Isso é importante tanto na apresentação, para mostrar suporte na pouca interface que temos, mas também para caso um membro do projeto queira estudar, se baseie naquilo.


- Todo código deve ter consistência e uma opção de saída


- STRUCTS em .h


### Professor (Nome,Cpf, Senha, Privilégio)


- O professor deve receber um alerta em todo login, uma vez que houver passado a aula qual foi prometida avaliação sem a atribuição da nota


### Funções


- **Materias**
- **Sair (Logout)**


### Funções descritas dentro das Materias {


- Presença
- Chamada
  Mostrará no topo a aula atual (de forma linear, sem alteração) exibindo abaixo o nome de aluno por aluno. O professor digitará "y" para presente, "n" para atribuir a falta para cada um até o ultimo, depois exibindo "Chamada concluida!".

- (?) - Ver as Faltas
  Exibir uma lista dos matriculados na matéria e a falta logo ao lado


- Alterar presença
  Exibir as aulas, o professor vai digitar o número da aula que ele vai entrar e então fazá a procura pelo nome de qual aluno vai fazer a alteração, exibindo o mesmo template do que seria a chamada do respectivo dia de aula para somente o respectivo usuário .


- Atribuição das notas (Forma avaliativa):
    - Adicionar forma avaliativa:
        - A nota pode ser construida pelo professor, sendo o padrão (p1 + p2) / 2, caso precise de recuperação += rec/2. O menu deve solicitar quantas formas avaliativas serão, após isso entitular uma por uma (O comando /finalizar deve finalizar as quantias de termos avaliativos, como p1,p2, t1, t2, a1, etc..). O professor após bolar a fórmula deve cadastrar em qual aula ele fará as avaliações.


- Editar avaliações
    - Data
        - Exibirá todas as avaliações. Com a avaliação selecionada professor pode alterar a data de uma prova, trabalho ou atividade, com o limite da ultima aula.
    - Forma avaliativa
        - O código fará a mesma etapa da função "Adicionar forma avaliativa". No final, ele deve exibir as duas formas avaliativas, contendo seus termos avaliativos, e questionando se deseja realmente substituir o termo avaliativo, caso ele pressione "y", substitui, caso "n", não substituirá.
    - (IMPORTANTE!!! A substituição não deve ser armazenada em nenhum FILE até que o usuário digite "y" na confirmação, ou seja, não deve ser persistente até dada a confirmação)


- Preencher notas
    - As notas podem ser preenchidas a qualquer momento, mesmo que já tenha passado a aula referente a avaliação (mas no login do professor, deve avisar a pendência de preenchimento a cada login).

### }

