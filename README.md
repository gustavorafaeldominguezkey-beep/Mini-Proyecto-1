# Mini-Proyecto-1
# Reglas para:RafCode - Mini Proyecto 1
Esto es un Mini compilador académico basado en las primeras reglas de mi lenguaje RafCode.
 Mini compilador académico desarrollado en lenguaje C.


## Mis Componentes
- Analizador léxico: `src/lexer.c`
- Analizador sintáctico: `src/parser.c`
- Analizador semántico: `src/semantic`
- AST y Tabla de Símbolos: `src/tables.c`
- Programa principal: `src/main.c`


## Compilar en Visual Studio Code / PowerShell

Desde la carpeta raíz del proyecto:

```powershell
gcc src/main.c src/lexer.c src/parser.c src/semantic.c src/ast.c src/symbol_table.c -o rafcode.exe
```

## Para Ejecutar:

```powershell
.\rafcode.exe examples\programa.raf
```

## Esta es las Pruebas de errores:

```powershell
.\rafcode.exe examples\programa_error_sintactico.raf
.\rafcode.exe examples\programa_error_semantico.raf
```

## Reglas RafCode

```text
crear nombre como tipo;
crear nombre como tipo = valor;
nombre = valor;
```

Tipos: entero, decimal, texto, booleano, caracter.


## Flujo del compilador
Código RafCode -> Lexer -> Parser -> AST -> Analizador Semántico -> Tabla de Símbolos -> Resultado.
