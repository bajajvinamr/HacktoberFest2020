import sys

PythonVersion = sys.version_info.major

if(PythonVersion < 3):
    try:
        from Tkinter import *
        from Tkinter import filedialog
        from Tkinter import messagebox
    except ImportError:
        raise ImportError("Se requiere el módulo de Tkinter.")
else:
    try:
        from tkinter import *
        from tkinter import filedialog
        from tkinter import messagebox
    except ImportError:
        raise ImportError("Se requiere el módulo de Tkinter.")

class BlocDeNotas(Frame):
    def __init__(self, master = None):
        super().__init__(master)
        self.master = master
        self.pack()
        self.config()
        self.__generarEspacio()
        Label(self, text = "HOLIS", font = ("Arial", 40))
    
    def __generarEspacio(self):
        self.nombreDeArchivo = "Sin título"
        self.rutaDeArchivo = ""
        self.__definirTitulo()
        self.__generarMenu()
        self.__generarEspacioDeTexto()
        self.__generarPie()

    def __definirTitulo(self):
        self.master.title(f"{self.nombreDeArchivo}: Bloc de notas")
            
    def __generarMenu(self):
        barraMenu = Menu(self.master)
        self.master.config(menu = barraMenu)

        archivoMenu = Menu(barraMenu, tearoff = 0)
        barraMenu.add_cascade(label = "Archivo", menu = archivoMenu)

        archivoMenu.add_command(label = "Nuevo", command = self.__nuevoArchivo)
        archivoMenu.add_command(label = "Abrir...", command = self.__abrirArchivo)
        archivoMenu.add_command(label = "Guardar", command = self.__guardarArchivo)
        archivoMenu.add_command(label = "Guardar como...", command = self.__guardarArchivoComo)
        archivoMenu.add_separator()
        archivoMenu.add_command(label = "Salir", command = self.master.destroy)

        edicionMenu = Menu(barraMenu, tearoff = 0)
        barraMenu.add_cascade(label = "Edición", menu = edicionMenu)
        edicionMenu.add_command(label = "Fuente", command = self.__fuente)
        edicionMenu.add_command(label = "Deshacer", command = self.__deshacer)
        edicionMenu.add_command(label = "Rehacer", command = self.__rehacer)

        ayudaMenu = Menu(barraMenu, tearoff = 0)
        barraMenu.add_cascade(label = "Ayuda", menu = ayudaMenu)
        ayudaMenu.add_command(label = "Acerca del Bloc de notas", command = self.__acercaDe)

    def __generarEspacioDeTexto(self):
        self.deshacer = []
        self.rehacer = []
        self.tamañoDeTexto = 12
        self.espacioDeTexto = Text(self.master, wrap = WORD, undo = True, width = 10, height = 10, padx = 3, font = ("Arial", self.tamañoDeTexto))
        self.espacioDeTexto.pack(side = LEFT, fill = 'both', expand = 1)
        self.espacioDeTexto.config()
        self.scrollVertical = Scrollbar(self.master, command = self.espacioDeTexto.yview)
        self.scrollVertical.pack(side = RIGHT, fill = 'both')
        self.espacioDeTexto.config(yscrollcommand = self.scrollVertical.set)
        self.espacioDeTexto.bind("<Key>", self.__agregarAlBuffer)

    def __generarPie(self):
        #En un futuro...
        pass

    def __nuevoArchivo(self):
        self.espacioDeTexto.delete("1.0", "end")
        self.rutaDeArchivo = ""
        self.nombreDeArchivo = "Sin título"
        self.__definirTitulo()


    def __abrirArchivo(self):
        self.espacioDeTexto.delete("1.0", "end")
        self.rutaDeArchivo = filedialog.askopenfilename(title = "Abrir", filetypes = (("Documentos de texto", "*.txt"), ("Todos los archivos", "*.*")))
        self.__obtenerNombre()
        self.__definirTitulo()
        self.fichero = open(self.rutaDeArchivo, "a+", encoding="UTF-8")
        self.fichero.seek(0)
        self.espacioDeTexto.insert(INSERT, self.fichero.read())
        del self.fichero

    def __guardarArchivo(self):
        if(self.nombreDeArchivo == "Sin título"):
            self.rutaDeArchivo = filedialog.asksaveasfilename(filetypes = (("Documentos de texto", "*.txt"), ("Todos los archivos", "*.*")))
            self.rutaDeArchivo = self.rutaDeArchivo.name
            self.__obtenerNombre()
            self.__definirTitulo()
            archivoTemporal = open(self.rutaDeArchivo, "w", encoding="UTF-8")
            archivoTemporal.write(self.espacioDeTexto.get("1.0", "end"))
            archivoTemporal.close()
            del archivoTemporal
        else:
            archivoTemporal = open(self.rutaDeArchivo, "w", encoding="UTF-8")
            archivoTemporal.write(self.espacioDeTexto.get("1.0", "end"))
            archivoTemporal.close()
            del archivoTemporal
        self.espacioDeTextoDeTexto.edit_reset() 


    def __guardarArchivoComo(self):
        self.rutaDeArchivo = filedialog.asksaveasfile(filetypes = (("Documentos de texto", "*.txt"), ("Todos los archivos", "*.*")))
        self.rutaDeArchivo = self.rutaDeArchivo.name
        self.__obtenerNombre()
        self.__definirTitulo()
        archivoTemporal = open(self.rutaDeArchivo, "w", encoding="UTF-8")
        archivoTemporal.write(self.espacioDeTexto.get("1.0", "end"))
        archivoTemporal.close()
        del archivoTemporal
        self.espacioDeTextoDeTexto.edit_reset()

    def __obtenerNombre(self):
        self.nombreDeArchivo = ""
        for i in self.rutaDeArchivo:
            if(i == "/"):
                self.nombreDeArchivo = ""
            else:
                self.nombreDeArchivo += i

    def __acercaDe(self):
        messagebox.showinfo("Acerca del Bloc de notas", "Bloc de notas\nVersión 1.0\nDesarrollado por HyDev\nE-mail: hydeefs@gmail.com")

    def __fuente(self):

        def cambiosEnFuente():
            if(self.entradaTamañoDeTexto.get() == ""):
                pass
            else:
                self.tamañoDeTexto = int(self.entradaTamañoDeTexto.get())
                self.espacioDeTexto.config(font = ("Arial", self.tamañoDeTexto))
            rootFuente.destroy()

        rootFuente = Tk()

        rootFuente.title("Fuente")
        Label(rootFuente, text = "Tamaño de fuente:").grid(row = 0, column = 0, padx = 5, pady = 5)
        tamañoDeTexto = StringVar()
        self.entradaTamañoDeTexto = Entry(rootFuente, textvariable = tamañoDeTexto, font = ("Arial", 12), width = 10)
        self.entradaTamañoDeTexto.grid(row = 0, column = 1, padx = 5, pady = 5)
        Button(rootFuente, text = "Cancelar", command = rootFuente.destroy).grid(row = 1, column = 0, padx = 5, pady = 5)
        Button(rootFuente, text = "Aceptar", command = cambiosEnFuente).grid(row = 1, column = 1, padx = 5, pady = 5)
        rootFuente.mainloop()

    def __deshacer(self):
        self.espacioDeTexto.edit_undo()


    def __rehacer(self):
        self.espacioDeTexto.edit_redo()

    def __agregarAlBuffer(self, event):
        if(event.char.isalnum() or event.char.isspace() or self.__verificarSimbolo(event.char)):
            self.espacioDeTexto.edit_separator()

    def __verificarSimbolo(self, char):
        for i in ["\"","!","¡","?","¿","'","@","#",".",";",",","-","_","°","|","/","*","-","+","´","~","`","[","]","{","}",":","&","%","$","(",")","="]:
            if(i == char):
                return True
        return False  
       

root = Tk()
root.geometry("1024x764")
root.config()
blocDeNotas = BlocDeNotas(master = root)
root.mainloop()
