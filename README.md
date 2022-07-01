<span style="color:;font-weight:500;font-size:15px; text-align:justify">


# <center> <b> Projeto de Bancos de Dados </b>
#### <center> Registro de vacinação - Clínica Veterinária Happy Pet
<br>

## <center> **Dicionário de Entidades**

1. CARGO <p>
  
|<center>CAMPO|<center>TIPO|<center>PERMITE NULOS|<center>TIPO DE CHAVE|<center>VALOR PADRÃO|<center>EXTRA|
|:-:|:-:|:-:|:-:|:-:|:-:|
|  ID  | int        | NO | PRI | NULL |auto_increment|
| NOME |varchar(100)| NO | UNI | NULL |-|

2. ESPECIE <p>
  
|<center>CAMPO|<center>TIPO|<center>PERMITE NULOS|<center>TIPO DE CHAVE|<center>VALOR PADRÃO|<center>EXTRA|
|:-:|:-:|:-:|:-:|:-:|:-:|
|   ID      |   int         |   NO  |  PRI |    NULL    |auto_increment|
|   NOME    |   varchar(45) |   NO  |  UNI |    NULL    |      -       |

3. FUNCIONARIO <p>
  
|<center>CAMPO|<center>TIPO|<center>PERMITE NULOS|<center>TIPO DE CHAVE|<center>VALOR PADRÃO|<center>EXTRA|
|:-:|:-:|:-:|:-:|:-:|:-:|
|    ID      | int          | NO | PRI |NULL|auto_increment  |
|    NOME    | varchar(100) | NO | UNI |NULL|        -       |
| NASCIMENTO | date         | NO |  -  |NULL|        -       |
|  TELEFONE  | varchar(15)  | NO |  -  |NULL|        -       |
|   EMAIL    | varchar(150) | NO |  -  |NULL|        -       |
|   CRMV     | varchar(20)  | YES| UNI |NULL|-|
|  CARGO_ID  | int          | NO | MUL |NULL|        -       |



4. PET <p>
  
|<center>CAMPO|<center>TIPO|<center>PERMITE NULOS|<center>TIPO DE CHAVE|<center>VALOR PADRÃO|<center>EXTRA|
|:-:|:-:|:-:|:-:|:-:|:-:|
|   ID       |   int         |   NO  |   PRI |NULL |auto_increment  |
|   NOME     |   varchar(100)|   NO  |   -   |NULL |        -       |
|   SEXO     |   varchar(5)  |   NO  |   -   |NULL |        -       |
|NASCIMENTO  |   date        |   NO  |   -   |NULL |        -       |
|CASTRADO    |   varchar(3)  |   NO  |   -   |"Não"|        -       |
|   PESO     |   double      |   NO  |   -   |NULL |        -       |
|  RACA_ID   |   int         |   NO  |   MUL |NULL |        -       |


5. RACA <p>
  
|<center>CAMPO|<center>TIPO|<center>PERMITE NULOS|<center>TIPO DE CHAVE|<center>VALOR PADRÃO|<center>EXTRA|
|:-:|:-:|:-:|:-:|:-:|:-:|
|   ID      |   int         |   NO  |   PRI |NULL             |auto_increment|
|   NOME    |   varchar(200)|   NO  |  UNI  |NULL             |     -        |
| PORTE     |   varchar(3)  |   NO  |   -   |NULL             |     -        |
| OBSERVACAO| varchar(1000) |   NO  |   -   |"Sem observações"|     -        |
|ESPECIE_ID |  int          |   NO  |   MUL |NULL             |     -        |


6. TUTOR <p>
  
|<center>CAMPO|<center>TIPO|<center>PERMITE NULOS|<center>TIPO DE CHAVE|<center>VALOR PADRÃO|<center>EXTRA|
|:-:|:-:|:-:|:-:|:-:|:-:|
|    ID      |   int          |   NO  |  PRI |NULL| auto_increment |
|    NOME    |   varchar(100) |   NO  |  UNI |NULL|        -       |
| NASCIMENTO |   date         |   NO  |  -   |NULL|        -       |
|  TELEFONE  |   varchar(15)  |   NO  |  -   |NULL|        -       |
|   EMAIL    |   varchar(150) |   NO  |  -   |NULL|        -       |

7. TUTOR_TEM_PET <p>
  
|<center>CAMPO|<center>TIPO|<center>PERMITE NULOS|<center>TIPO DE CHAVE|<center>VALOR PADRÃO|<center>EXTRA|
|:-:|:-:|:-:|:-:|:-:|:-:|
|  TUTOR_ID |   int    |   NO  |  PRI | NULL | - |
|  PET_ID   |   int    |   NO  |  PRI | NULL | - |


8. USUARIO <p>
  
|<center>CAMPO|<center>TIPO|<center>PERMITE NULOS|<center>TIPO DE CHAVE|<center>VALOR PADRÃO|<center>EXTRA|
|:-:|:-:|:-:|:-:|:-:|:-:|
| ID    | int          | NO | PRI | NULL | auto_increment |
| LOGIN | varchar(100) | NO | UNI | NULL |        -       |
| SENHA | varchar(256) | NO |  -  | NULL |        -       |


9. VACINA <p>
  
|<center>CAMPO|<center>TIPO|<center>PERMITE NULOS|<center>TIPO DE CHAVE|<center>VALOR PADRÃO|<center>EXTRA|
|:-:|:-:|:-:|:-:|:-:|:-:|
|  ID      | int          | NO |PRI| NULL | auto_increment |
|  NOME    | varchar(200) | NO | - | NULL |         -      |
| DESCRICAO| varchar(1000)| NO | - | NULL |         -      |
|  MARCA   | varchar(100) | NO | - | NULL |         -      |
|ESPECIE_ID| int          | NO |MUL| NULL |         -      |


10. VACINACAO <p>
  
|<center>CAMPO|<center>TIPO|<center>PERMITE NULOS|<center>TIPO DE CHAVE|<center>VALOR PADRÃO|<center>EXTRA|
|:-:|:-:|:-:|:-:|:-:|:-:|
|    PET_ID          |   int         | NO | PRI | NULL |-|
|  VACINA_ID         |   int         | NO | PRI | NULL |-|
|  FUNCIONARIO_ID    |   int         | NO | PRI | NULL |-|

## <center> **Procedimentos**

1. INSERIR_RACA <p>
Insere a raça de modo que o usuario possa textualmente a qual espécie a raça pertence.


```sql
DELIMITER //
CREATE PROCEDURE INSERIR_RACA(NOME_DA_RACA VARCHAR(200), PORTE_DA_RACA VARCHAR(3), OBSERVACAO_DA_RACA VARCHAR(1000), NOME_ESPECIE VARCHAR(45))
BEGIN
	DECLARE ESPECIE_ID_LOCAL INT;
	IF OBSERVACAO_DA_RACA LIKE "" THEN
		SET OBSERVACAO_DA_RACA = "Sem observações";
	END IF;

    SET ESPECIE_ID_LOCAL := (SELECT ID FROM ESPECIE WHERE ESPECIE.NOME = NOME_ESPECIE);
    IF ESPECIE_ID_LOCAL > 0 THEN
    	INSERT IGNORE INTO RACA (NOME, PORTE, OBSERVACAO, ESPECIE_ID)
		VALUES (NOME_DA_RACA, PORTE_DA_RACA, OBSERVACAO_DA_RACA, ESPECIE_ID_LOCAL);
	ELSE
		SELECT CONCAT("O nome da espécie informado '", NOME_ESPECIE,"' NÃO EXISTE OU É INVÁLIDO!") AS ERRO;
	END IF;
END //
DELIMITER ;
```
<p>

2. VALIDAR_CRMV <p>
Como o uso de CRMV só é válido para veterinários, (já que inicialmente os dados foram inseridos aleatoriamente), altera o CRMV dos funcionários que não são veterinários para "Funcionário sem CRMV".
```sql
DELIMITER //
CREATE PROCEDURE VALIDAR_CRMV()
BEGIN
        UPDATE FUNCIONARIO SET CRMV = "Funcionário sem CRMV" WHERE CARGO_ID > 1;
END //
DELIMITER ;
```


3. VACINAR_PETS <p>
Com base na idade dos pets (já que até o momento se tratam de dados aleatórios), os PETS cadastrados no sistema recebem dados de vacinação de acordo com a idade.
Não permitindo assim que uma data de vacina seja incluída com data anterior ao nascimento do pet.


```sql
DELIMITER //
CREATE PROCEDURE VACINAR_PETS()
BEGIN
	DECLARE CONTADOR_DE_PETS INT DEFAULT 1;
    DECLARE CONTADOR_DE_VACINACAO INT DEFAULT 1;
    DECLARE TOTAL_DE_PETS INT;
    DECLARE IDENTIFICADOR_PET INT;
    DECLARE IDENTIFICADOR_FUNCIONARIO INT;
    DECLARE NASCIMENTO_PET DATE;
	DECLARE MESES_DE_IDADE INT;
    DECLARE DATA_DE_VACINACAO DATE;

    SET CONTADOR_DE_PETS := 1;
    SET TOTAL_DE_PETS := (SELECT COUNT(*) FROM PET);
	WHILE (CONTADOR_DE_PETS < TOTAL_DE_PETS) DO
		SET IDENTIFICADOR_PET := (SELECT ID FROM PET WHERE ID = CONTADOR_DE_PETS);
        SET IDENTIFICADOR_FUNCIONARIO := (SELECT ID FROM FUNCIONARIO WHERE CARGO_ID = 1 ORDER BY RAND() LIMIT 1);
        SET MESES_DE_IDADE := (SELECT IDADE_PET_EM_MESES(ID) FROM PET WHERE ID = IDENTIFICADOR_PET);
        SET NASCIMENTO_PET := (SELECT NASCIMENTO FROM PET WHERE ID = IDENTIFICADOR_PET);
        SET DATA_DE_VACINACAO := (SELECT DATE_ADD(NASCIMENTO_PET, INTERVAL 30 DAY));
        IF MESES_DE_IDADE <= 3 THEN
		INSERT INTO VACINACAO (PET_ID, VACINA_ID, FUNCIONARIO_ID, DATA_VACINACAO) VALUES (IDENTIFICADOR_PET, 1, IDENTIFICADOR_FUNCIONARIO, DATA_DE_VACINACAO);
		ELSEIF MESES_DE_IDADE > 3 AND MESES_DE_IDADE < 18 THEN
			WHILE CONTADOR_DE_VACINACAO < 5 DO
				SET DATA_DE_VACINACAO := (SELECT DATE_ADD(DATA_DE_VACINACAO, INTERVAL 2 MONTH));
				INSERT INTO VACINACAO (PET_ID, VACINA_ID, FUNCIONARIO_ID, DATA_VACINACAO) VALUES (IDENTIFICADOR_PET, CONTADOR_DE_VACINACAO, IDENTIFICADOR_FUNCIONARIO, DATA_DE_VACINACAO);
                SET CONTADOR_DE_VACINACAO = CONTADOR_DE_VACINACAO + 1;
			END WHILE;
            SET CONTADOR_DE_VACINACAO = 1;
		ELSE
			WHILE CONTADOR_DE_VACINACAO < 5 DO
				SET DATA_DE_VACINACAO := (SELECT DATE_ADD(DATA_DE_VACINACAO, INTERVAL 2 MONTH));
				INSERT INTO VACINACAO (PET_ID, VACINA_ID, FUNCIONARIO_ID, DATA_VACINACAO) VALUES (IDENTIFICADOR_PET, CONTADOR_DE_VACINACAO, IDENTIFICADOR_FUNCIONARIO, DATA_DE_VACINACAO);
                SET CONTADOR_DE_VACINACAO = CONTADOR_DE_VACINACAO + 1;
			END WHILE;
            SET CONTADOR_DE_VACINACAO = 1;
		END IF;
        SET CONTADOR_DE_PETS = CONTADOR_DE_PETS + 1;
    END WHILE;
    COMMIT;
END//
DELIMITER ;
```

4. SETAR_USUARIOS <p>
Por padrão, cada usuário deve ter acesso ao sistema com uma única conta.
E de forma a padronizar o acesso inicial às contas, o login é criado automaticamente com base no primeiro e último nome de cada funcionário.
De forma similar, as senhas dos usuários estarão setadas automaticamente como a data de seu nascimento (no formato: diaanomes, sem traços)<p>
Exemplo: Funcionário chamado Kelvin Coelho Loiola e nascido em 1987-12-28.
<br> O login será: Kelvin.Loiola
<br> A Senha será: 28121987

```sql
DELIMITER //
CREATE PROCEDURE SETAR_USUARIOS()
BEGIN

	DECLARE IDENTIFICADOR INT;
    DECLARE CONTADOR INT DEFAULT 0;
    DECLARE QNT_FUNCIONARIOS INT;
    DECLARE LOGIN_DO_FUNCIONARIO VARCHAR(100);
    DECLARE SENHA_DO_FUNCIONARIO VARCHAR(256);

    SET QNT_FUNCIONARIOS := (SELECT COUNT(*) FROM FUNCIONARIO);
    WHILE (CONTADOR < QNT_FUNCIONARIOS) DO
		SET LOGIN_DO_FUNCIONARIO := (SELECT CONCAT(regexp_substr(NOME, '[a-z]+', 1, 1), ".", regexp_substr(NOME, '[a-z]+', 1, 3)) FROM FUNCIONARIO WHERE ID = CONTADOR+1);
		SET SENHA_DO_FUNCIONARIO := (SELECT SHA2(CONCAT(REGEXP_SUBSTR(NASCIMENTO,'[0-9]+', 1, 3), REGEXP_SUBSTR(NASCIMENTO,'[0-9]+', 1, 2), REGEXP_SUBSTR(NASCIMENTO,'[0-9]+', 1, 1)), 256) FROM FUNCIONARIO WHERE ID = CONTADOR+1);
		INSERT IGNORE INTO USUARIO (LOGIN, SENHA, FUNCIONARIO_ID) VALUES (LOGIN_DO_FUNCIONARIO, SENHA_DO_FUNCIONARIO, CONTADOR+1);
		SET CONTADOR = CONTADOR + 1;
	END WHILE;
END//
DELIMITER ;

```
## **Funções**

1. IDADE_PET_EM_MESES <p>
Função para retorno da idade dos pets em meses. Auxiliando na execução de outras
etapas, com vacinação.
<br> Como exemplo, um pet com idade igual a 6 anos e 3 meses teria como retorno o valor igual a 75.

```sql
DELIMITER //
CREATE FUNCTION IDADE_PET_EM_MESES (IDENTIFICADOR INT) RETURNS INT DETERMINISTIC
BEGIN
	DECLARE DATA_NASCIMENTO DATE;
    DECLARE IDADE_MESES INT;
	SET DATA_NASCIMENTO := (SELECT NASCIMENTO FROM PET WHERE ID = IDENTIFICADOR);
	SET IDADE_MESES := TIMESTAMPDIFF(MONTH, DATA_NASCIMENTO, NOW());
	RETURN IDADE_MESES;
END //
DELIMITER ;
```


2. TRANSCREVER_IDADE_PET <p>
Outra função para retorno da idade dos pets.<br>
Entretanto, ao contrário da função anterior, esta função retorna a data 'por extenso'.
<br> Exemplo: Se um pet tem 75 meses, o retorno da função é: "6 anos e 3 meses"

```sql
DELIMITER //
CREATE FUNCTION TRANSCREVER_IDADE_PET(IDENTIFICADOR INT) RETURNS VARCHAR(30) DETERMINISTIC
BEGIN
	DECLARE DATA_NASCIMENTO DATE;
    DECLARE IDADE_MESES INT;

	SET DATA_NASCIMENTO := (SELECT NASCIMENTO FROM PET WHERE ID = IDENTIFICADOR);
    SET IDADE_MESES := TIMESTAMPDIFF(MONTH, DATA_NASCIMENTO, NOW());
    RETURN (SELECT CONCAT(IDADE_MESES DIV 12, " anos e ", IDADE_MESES%12, " meses") as IDADE FROM PET WHERE ID = IDENTIFICADOR);
END//
DELIMITER ;
```

3. FAIXA_ETARIA_PET<p>
Esta última função tem como objetivo definir faixas etárias para cada pet.<p>
Assim, temos as seguintes faixas:
- "PUPPY": Pets com até 3 meses de vida;
- "FILHOTE": Pets com idades entre 3 e 18 meses;
- "Adulto": Pets com idades entre 19 meses e 7 anos;
- "IDOSO": Pets com idades acima de 7 anos;

```sql
DELIMITER //
CREATE FUNCTION FAIXA_ETARIA_PET (IDENTIFICADOR INT) RETURNS VARCHAR(10) DETERMINISTIC
BEGIN
	DECLARE DATA_NASCIMENTO DATE;
    DECLARE IDADE_MESES INT;
	SET DATA_NASCIMENTO := (SELECT NASCIMENTO FROM PET WHERE ID = IDENTIFICADOR);
    SET IDADE_MESES = TIMESTAMPDIFF(MONTH, DATA_NASCIMENTO, NOW());
	IF IDADE_MESES <= 3 THEN
		RETURN "PUPPY";
	ELSEIF IDADE_MESES > 3 AND IDADE_MESES <= 18 THEN
		RETURN "FILHOTE";
	ELSEIF IDADE_MESES > 18 AND IDADE_MESES < 84 THEN
		RETURN "ADULTO";
	ELSE
		RETURN "IDOSO";
	END IF;
END//
DELIMITER ;
```
