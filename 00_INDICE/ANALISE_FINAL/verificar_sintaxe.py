from pathlib import Path
import subprocess,concurrent.futures,json
Path('/tmp/mp1-auditoria').mkdir(parents=True,exist_ok=True)
ps=[p for p in Path('.').rglob('*') if p.suffix.lower() in ['.c','.cpp'] and not any(x.startswith('.') for x in p.parts)]
def run(p):
 cmd=['gcc' if p.suffix=='.c' else 'g++','-std=gnu11' if p.suffix=='.c' else '-std=gnu++17','-Wall','-Wextra','-Wformat=2','-fsyntax-only',str(p)]
 try:
  r=subprocess.run(cmd,capture_output=True,text=True,timeout=30)
  return {'path':str(p),'command':cmd,'returncode':r.returncode,'diagnostics':r.stderr}
 except subprocess.TimeoutExpired:return {'path':str(p),'returncode':-1,'diagnostics':'timeout'}
with concurrent.futures.ThreadPoolExecutor(max_workers=3) as ex:r=list(ex.map(run,ps))
Path('/tmp/mp1-auditoria/compilacao.json').write_text(json.dumps(r,ensure_ascii=False,indent=2))
print('Analisados',len(r),'falhas',sum(x['returncode']!=0 for x in r))
for x in r:
 if x['returncode']: print(x['path'],x['diagnostics'][:1400])
