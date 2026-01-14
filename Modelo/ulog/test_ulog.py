from pyulog import ULog

ulog = ULog("prueba.ulg")

print("Mensajes encontrados:")
for d in ulog.data_list:
  print(d.name)
