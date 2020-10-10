import wx


class MyPanel(wx.Panel):

    def __init__(self, parent):
        super().__init__(parent)

        self.txtctrl1 = wx.TextCtrl(self, pos=(30, 30))
        self.label1 = wx.StaticText(self, label="Enter name", pos=(150, 30))

        self.btn1 = wx.Button(self, label="Move Text", pos=(40, 70))

        self.txtctrl2 = wx.TextCtrl(self, pos=(30, 110))
        self.label2 = wx.StaticText(self, label="Your text", pos=(150, 110))

        # connect button event to an event-handler function
        self.btn1.Bind(wx.EVT_BUTTON, self.OnMoveText)

    def OnMoveText(self, event):  # copy text from box 1 to box 2
        str1 = self.txtctrl1.GetValue()  # get text from first text control
        if str1 == "":
            str1 = "no text entered"
        self.txtctrl2.SetValue(str1)  # set text into second text control


class MyFrame(wx.Frame):
    def __init__(self, parent, id, title):
        super(MyFrame, self).__init__(parent, id, title)

        panel = MyPanel(self)


app = wx.App(False)
frame = MyFrame(None, -1, 'Simple.py')
frame.Show(True)
app.MainLoop()