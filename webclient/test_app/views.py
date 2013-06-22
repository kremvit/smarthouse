from django.http import HttpResponse
from django.template import Context, loader

import json, socket

from test_app.models import PC

def index(request):
#    import pdb; pdb.set_trace()
#    pc_list = PC.objects.all()
#    pc = PC()
#    pc_list = pc.name()
    template = loader.get_template('test_app/index.html')

    s = socket.create_connection(("localhost", 8086))
    s.sendall(
	json.dumps({"jsonrpc":"2.0" ,"id": 1, "method": "getdevicelist"}))
    pc_list = s.recv(4096).decode()
    import pdb; pdb.set_trace()
    json.loads(pc_list)
    context = Context({"pc_list": pc_list})

    return HttpResponse(template.render(context))
