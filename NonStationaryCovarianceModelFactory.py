import openturns as ot
from math import exp
from matplotlib import pyplot as plt
from openturns.viewer import View


# Create the covariance function at (s,t)

def C(s, t):
  return exp( -4.0 * abs(s - t) / (1 + (s * s + t * t)))

def covModRef(X):
  return [C(X[0], X[1])]

myFuncCovarianceRef = ot.PythonFunction(2, 1, covModRef)
myFuncCovarianceRef.setDescription(["s", "t", "C"])

t0 = -4.0
tmax = 4.0

# Draw the isocontours of the discretized covariance function
print "draw the reference"
myGraphRef = myFuncCovarianceRef.draw([t0, t0], [tmax, tmax])
alld = myGraphRef.getDrawables()
palette = ot.Drawable.BuildDefaultPalette(alld.getSize())
levels = ot.NumericalPoint(alld.getSize())
for i in range(alld.getSize()):
  print "i=", i
  d = alld[i]
  d.setLineStyle("twodash")
  d.setLineWidth(2)
  d.setColor(palette[i])
  myGraphRef.setDrawable(d, i)
  levels[i] = d.getLevels()[0]

# Create the time grid
#for iN in range(2, 11):
#  t_00 = time()
N = 2**5
dt = (tmax - t0) / N
myMesh =  ot.RegularGrid(t0, dt, N)

# Keep only time stamps in the time-grid
tmax = myMesh.getEnd()

# Create the collection of HermitianMatrix
myCovarianceCollection = ot.CovarianceMatrixCollection()
index = 0
for k in range(N):
    s = myMesh.getValue(k)
    for l in range(k+1):
      t = myMesh.getValue(l)
      matrix = ot.CovarianceMatrix(1)
      matrix[0, 0] = C(s, t)
      index += 1
      myCovarianceCollection.add(matrix)

# Create the covariance model
myCovarianceModel = ot.UserDefinedCovarianceModel(myMesh, myCovarianceCollection)

# Create the non stationary Normal process with
# that covariance model
myProcess = ot.TemporalNormalProcess(myCovarianceModel, myMesh)

# Create a  sample of fields
size = 10**4
myFieldSample = myProcess.getSample(size)

# Build a covariance model factory
myFactory = ot.NonStationaryCovarianceModelFactory()

# Estimation on a the ProcessSample
myEstimatedModel = myFactory.build(myFieldSample)

# Define the python function associated to myCovarianceModel
def covMod(X):
      return [myEstimatedModel(X[0], X[1])[0, 0]]

myFuncCovariance = ot.PythonFunction(2, 1, covMod)


cov_graph = ot.Graph(myGraphRef)
alld = myFuncCovariance.draw([t0, t0], [tmax, tmax]).getDrawables()
for i in range(alld.getSize()):
      d = alld[i]
      d.setLegend("")
      d.setLevels([levels[i]])
      d.setColor(palette[i])
      d.setDrawLabels(False)
      cov_graph.add(d)
      
fig = plt.figure(figsize=(10, 4))
plt.suptitle('Non stationary covariance model estimation')
cov_axis = fig.add_subplot(111)
view = View(cov_graph, figure=fig, axes=[cov_axis], add_legend=False)
view.show()
cov_graph.draw("toto.png")
