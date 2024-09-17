% Questão 1
contador([], 0).
contador([_ | T], X) :-
    contador(T, X1),
    X is X1 + 1.

% Questão 2
maior_valor([X], X).

maior_valor([X | Tail], MaiorValor) :-
    maior_valor(Tail, MaiorValorCauda),
    (X > MaiorValorCauda -> MaiorValor = X ; MaiorValor = MaiorValorCauda).
    
% Questão 3
% Soma os elementos de uma lista
somar_lista([], 0).
somar_lista([Head | Tail], Soma) :-
    somar_lista(Tail, SomaTail),
    Soma is Head + SomaTail.

% Conta os elementos de uma lista
contar_numeros([], 0).
contar_numeros([_ | Tail], X) :-
    contar_numeros(Tail, X1),
    X is X1 + 1.

% Faz a média usando as 2 funções
calcula_media(Lista, Media) :-
    somar_lista(Lista, Soma),
    contar_numeros(Lista, QtdNumeros),
    QtdNumeros > 0,        % Verifica se há elementos na lista
    Media is Soma / QtdNumeros.
    
% Questão 4
inserir_final(Numero, [], [Numero]).
inserir_final(Numero, [Head|Tail], [Head|NewTail]) :-
    inserir_final(Numero, Tail, NewTail).
    
% Questão 5
ultimo_elemento([Elemento], Elemento).

ultimo_elemento([_|Tail], Ultimo) :-
    ultimo_elemento(Tail, Ultimo).
    
% Questão 6
numero_adjacente(Numero1, Numero2, [Numero1, Numero2|_]).
numero_adjacente(Numero1, Numero2, [_|Tail]) :-
    numero_adjacente(Numero1, Numero2, Tail).
    
% Questão 7
    % se X é igual Y, acabou o intervalo
intervalo_fechado(X, X, [X]).

% se X é menor que Y
intervalo_fechado(X, Y, [X|Tail]) :-
    X < Y,
    SumX is X + 1,
    intervalo_fechado(SumX, Y, Tail).

% se X é maior que Y
intervalo_fechado(X, Y, [X|Tail]) :-
    X > Y,
    SubX is X - 1,
    intervalo_fechado(SubX, Y, Tail).

% Questão 8
inverter_lista([], ListaInversa, ListaInversa).

inverter_lista([Head | Tail], ListaInversa, Invertida) :-
    inverter_lista(Tail, [Head | ListaInversa], Invertida).

inverter_lista(Lista, Invertida) :-
    inverter_lista(Lista, [], Invertida).

% Questão 9
incrementar_lista([], []).

incrementar_lista([Head | Tail], [NewHead | NewTail]) :-
    NewHead is Head + 1,
    incrementar_lista(Tail, NewTail).

% Questão 10
remover_numero(_, [], []).

% Se o primeiro elemento for igual a X, não jogamos na lista.
remover_numero(X, [X | Tail], ListaSemNumero) :-
    remover_numero(X, Tail, ListaSemNumero).

% Se o primeiro elemento for diferente de X, mantemos ele na lista.
remover_numero(X, [Head | Tail], [Head | NewTail]) :-
    X \= Head,
    remover_numero(X, Tail, NewTail).
