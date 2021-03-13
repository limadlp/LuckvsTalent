# LuckvsTalent

 É comum que associemos sucesso financeiro com inteligência (talento, notas na escola, Q.I., etc.), mas a verdade é que há muitos fatores aleatórios a serem considerados e que na prática nem sempre os mais ricos são os mais inteligentes e nem sempre os mais inteligentes são os mais ricos.
Para demonstrar que não há tanta conexão entre inteligência e sucesso financeiro, simulei um modelo de sorte vs inteligência baseado em um artigo que li recentemente. (Original aqui:https://arxiv.org/pdf/1802.07068.pdf).

O modelo original é baseado em agentes, os eventos seguem uma caminhada aleatoria num espaço bidimensional, foi programado em Netlogo. A minha versão dispensa a necessidade de um espaço e considera que os eventos sejam sorteados a cada iteração de acordo com uma determinada probabilidade e foi programado em C++ e em Python.

Regras:

    Consideramos uma população de N indivíduos não interagentes.
    Cada indivíduo tem associado um valor de 0 a 1 que corresponde à sua inteligência (que pode ser associada ao Q.I., à média nos anos de escola, ou a um talento subjetivo).
    Todo mundo começa com a mesma quantia em dinheiro (capital).
    A cada seis meses cada um dos indivíduos está sujeito a um de três eventos ao acaso: Evento Neutro, Evento Bom, Evento Ruim. 
        Se o evento for neutro, nada acontece com o capital do indivíduo.
        Se o evento for ruim, o capital financeiro do indivíduo cai pela metade, independente da sua inteligência (o azar é para todos).
        Se o evento for bom, o capital do indivíduo dobra com uma probabilidade que é proporcional à sua inteligência (supondo dessa maneira que os mais inteligentes possuem mais chances de descobrir e aproveitar oportunidades de crescimento financeiro).
    A simulação acontece por 40 anos (80 iterações de 6 meses).


Parâmetros:
Número de indivíduos: 1000
Número de iterações: 80
Capital inicial: 10
Probabilidade de evento bom: 0.05
Probabilidade de evento ruim: 0.05
Probabilidade de evento neutro: 0.9
Talento: gaussiano ,média 0.6, sigma 0.1


Na apresentação de slides em pdf há os gráficos com os resultados da simulação, bem como uma segunda proposta de modelo.
