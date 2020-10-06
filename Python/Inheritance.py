class player:
    def __init__(self, name, age):
        self.name=name
        self.age=age
        
class batsman(player):
    def __init__(self,name,age,run,ball,rrbat):
        player.__init__(self,name,age)
        self.run=run
        self.ball=ball
        self.rrbat=rrbat
class bowler(player):
    def __init__(self,name,age,over,wicket,rrball,run):
        player.__init__(self,name,age)
        self.over=over
        self.wicket=wicket
        self.rrball=rrball
        self.run=run
class allrounder(batsman,bowler):
      def __init__(self,name,age,run,ball,rrbat,over,wicket,rrball):
          batsman.__init__(self,name,age,run,ball,rrbat)
          bowler.__init__(self,name,age,over,wicket,rrball,run)

aa=allrounder('ram',26,123,100,123.00,10,3,5.6)
print(aa.name)
print(aa.age)
print(aa.rrball)
print(aa.over)
    
