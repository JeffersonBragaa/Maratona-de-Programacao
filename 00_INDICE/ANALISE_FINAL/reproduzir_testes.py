from pathlib import Path
import subprocess,json,random,math
base=Path('/tmp/mp1-auditoria');base.mkdir(parents=True,exist_ok=True);results=[]
cases=[
('01_LISTAS/LISTA_04/1763.cpp','brasil\n','Feliz Natal!\n','tradução da primeira linha'),
('01_LISTAS/LISTA_04/1548.cpp','1\n3\n100 100 90\n','3\n','notas iguais mantêm posições'),
('02_SIMULADOS_E_PROVAS/SIMULADO_02/K.cpp','3 3\n1 1\n1 100 200\n2 3 4\n0 0\n','YES\n','selecionar subconjuntos conforme PDF p20'),
('07_AVALIACOES_EM_SALA/WARMUP_AULA_10/c.cpp','6 3\n2 0 1\n3 2 3 4\n2 2 0\n0 0\n','5\n','grupo conectado a zero tem cinco membros'),
('03_ALGORITMOS/TARJAN/aula.cpp','3 2\n0 1\n1 2\n','numSCC = 3','três componentes unitárias; comparação por prefixo'),
('01_LISTAS/LISTA_07/2840.cpp','1 100\n','23\n','modelo de volume esférico presente no código; enunciado não confirmado'),
('01_LISTAS/LISTA_07/3068.cpp','0 10 10 0\n4\n0 0\n10 10\n5 5\n11 5\n0 0 0 0\n','Teste 1\n3\n','fronteiras inclusivas do retângulo no modelo implementado'),
('01_LISTAS/LISTA_07/3152.cpp','0 0\n2 0\n2 2\n0 2\n0 0\n1 0\n1 1\n0 1\n','terreno A\n','áreas 4 e 1'),
('01_LISTAS/LISTA_07/1549.cpp','1\n1 3\n1 1 10\n','0.95\n','cilindro: h=3/pi'),
('01_LISTAS/LISTA_07/1982.cpp','4\n0 0\n1 0\n1 1\n0 1\n0\n','Tera que comprar uma fita de tamanho 4.00.\n','perímetro do quadrado unitário'),
('01_LISTAS/LISTA_07/1124.cpp','4 4 1 1\n3 3 1 1\n0 0 0 0\n','S\nN\n','dois círculos em retângulo'),
('01_LISTAS/LISTA_07/1296.cpp','3 3 3\n1 2 3\n','5.196\n-1.000\n','área por medianas e degeneração'),
('01_LISTAS/LISTA_04/1340.cpp','1\n2 10\n',None,'remoção vazia: verificação de pré-condição com libstdc++ debug'),
('02_SIMULADOS_E_PROVAS/SIMULADO_02/B.cpp','1\n1 10\n',None,'limites do vetor com libstdc++ debug'),
('01_LISTAS/LISTA_05/1029.cpp','1\n0\n',None,'caso zero: limites do vetor com libstdc++ debug')]
rng=random.Random(20261113); inp='';expected=[]
for _ in range(100):
 ps=[(rng.randint(-100,100),rng.randint(-100,100)) for _ in range(rng.randint(2,40))]
 inp+=str(len(ps))+'\n'+''.join(f'{x} {y}\n' for x,y in ps)
 expected.append(f'{min(math.dist(a,b) for i,a in enumerate(ps) for b in ps[i+1:]):.4f}')
cases.append(('01_LISTAS/LISTA_07/1295.cpp',inp+'0\n','\n'.join(expected)+'\n','100 casos aleatórios comparados com todos os pares; semente 20261113'))
for k,(p,inp,exp,note) in enumerate(cases):
 exe=base/f'test{k}'
 cmd=['g++','-std=gnu++17','-O0','-D_GLIBCXX_DEBUG',p,'-o',str(exe)]
 c=subprocess.run(cmd,capture_output=True,text=True,timeout=30)
 if c.returncode: results.append(dict(path=p,compile=c.stderr));continue
 try:r=subprocess.run([str(exe)],input=inp,capture_output=True,text=True,timeout=4)
 except subprocess.TimeoutExpired:results.append(dict(path=p,note=note,outcome='timeout'));continue
 ok=(r.stdout==exp or (p.endswith('TARJAN/aula.cpp') and r.stdout.startswith(exp))) if exp is not None else None
 results.append(dict(path=p,input=inp,expected=exp,stdout=r.stdout,stderr=r.stderr[:1600],returncode=r.returncode,matched=ok,note=note,command=cmd))
 print(p,'rc',r.returncode,'match',ok,'stdout',repr(r.stdout[:80]))
(base/'testes.json').write_text(json.dumps(results,ensure_ascii=False,indent=2))
