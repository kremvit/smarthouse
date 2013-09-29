from django.http import HttpResponse
from django.template import Context, loader
from django.http import HttpResponseRedirect

import json, socket

def index(request):
    template = loader.get_template('test_app/index.html')

    s = socket.create_connection(("localhost", 8086))
    s.sendall(json.dumps({"jsonrpc":"2.0" ,"id": 1, "method": "getdevicelist"}))

    pc_list = s.recv(4096).decode()

    obj = json.loads(pc_list)
    dev_list = obj['device_list']
    context = Context({"pc_list": dev_list})

    return HttpResponse(template.render(context))

def detail(request, pc_id):
    template = loader.get_template('test_app/detail.html')

    s = socket.create_connection(("localhost", 8086))
    s.sendall(json.dumps({"jsonrpc":"2.0" ,"id": 1, "device_id": int(pc_id),"method": "getdevice"}))

    pc = s.recv(4096).decode()

    obj = json.loads(pc)

    device = obj['device']

    context = Context({"pc": device})
    return HttpResponse(template.render(context))

def restart_pc(request, pc_id):
    s = socket.create_connection(("localhost", 8086))
    s.sendall(json.dumps({"jsonrpc":"2.0" ,"id": 1, "device_id": int(pc_id),"method": "restartdevice"}))
    return HttpResponseRedirect('/kremvit')