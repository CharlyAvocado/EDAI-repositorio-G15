import pandas as pd  
df = pd.read_csv("DB.csv")
casos_positivos=(len(df[df["indicador"]>=0.8]))
#print (df[df["indicador"]>=0.8])
print("El número de casos positivos es: ",casos_positivos)

if casos_positivos == 0:
	print("El semáforo es verde")
elif casos_positivos >=1<=30:
	print("El semáforo es amarillo")
elif casos_positivos >=31<=70:
	print("El semáforo es naranja")
elif casos_positivos >=71<=100:
	print("El semáforo es rojo")

print("La edad promedio de casos positivos es:",df[df["indicador"]>=0.8].agg({"edad":'mean'}))

agrupados_por_edad = df[df["indicador"]>=0.8].groupby("edad").count()
import matplotlib.pyplot as plt #pip install matplotlib
agrupados_por_edad.plot(kind="bar")
plt.show()