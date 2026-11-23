# 🌅 hackathon 2
## project structure

This repository of code gives the file structure you need in order to code with `raylib` and use Github Codespaces for this hackathon.

First read through the code here. There are some kinds of files we have not seen before in this class:
- `devcontainer`: some setup for running this project in VSCode/Github Codespaces
- `CMakeLists.txt`: a configuration file that will make compiling this project a lot simpler, as we will include multiple files + libraries

### to run the example, example.cpp
1. Read through `example.cpp` first. What will this file do? How does it do it? Look in the comments for links to the `raylib` documentation.
2. Find the green "Use this template" button - click that and choose "Create a new repository". This will be your own copy of this code.
3. In your new copy, click the green "Code" button and choose "Create codespace on main". This will open an IDE for you, a place to edit and run c++
4. This may take a few minutes to load initially! ⏰ ...
5. Find your files on the left, and your terminal at the bottom. When you are ready for the terminal, type the following and press enter:
 ```
  cmake -B build
```
This uses a tool called `cmake` which reads the `CMakeLists.txt` file and starts the compiling and build process in a folder called `build`. Next, type and press enter:
```
cmake --build build
```
This command completes the compiling process in the `build` folder, and adds your executable program (like `a.out`) to that folder. This replaces typing `g++`
Once that compiling is all finished, in the terminal type and press enter:
```
./build/example
```
This is just like when I type `./a.out` in class - except now we have a program called `example` that's in the `build` folder. Pressing enter here will start that program.

### 📺 important next step: rendering window

1. Near the Terminal tab, find the Ports tab.
2. Look for **Port 6080** - and find a little globe icon, you may have to hover over the URL in order to find this. Click the globe.
3. A new window should open in your browser, which is a **desktop simulator**. Click "Connect"
4. You should see the example code (Toby & Proton, cats) show in a graphics window. Press Escape to close the window when you're done.

### 🛠️ to write your own program
1. Put your team's code in `main.cpp`. Keep `example.cpp` as a working demo.
2. After changing code, you only need to run `cmake --build build` and then run `./build/main`
3. When you make a new class, you'll need to change and add to `CMakeLists.txt` - the comments in that file tells you where.
4. Remember to run you programs from the main folder, not from inside `build/`

### 💾 saving and sharing your work
Your files are saved in the Codespace, but Codespaces can be deleted after a period of inactivity. You need to "push" your changes to your code saved on github. At the end of every session: Source Control icon (left sidebar, 3 blobs connected by a line) → write a message → Commit → Sync Changes.

### how to run locally instead:

I set up Codespaces for this hackathon because it can be challenging to make sure all your team's install settings work for this library build. However, if you want to try to code locally, you just need to make sure you have [CMake](https://embedded.seas.upenn.edu/Guides/build-systems/getting-started-with-cmake/#__tabbed_1_1) and a c++ compiler installed on your machine. The CMake steps will be the same, you just won't need to find a Port to open a new window, it will open automatically.

### about codespaces

Codespaces is a free IDE on Github, but you only get 60 hours per month on the free plan. This should be fine for this project! I recommend you **Stop** the codespace when you are not using it. You can see a list of your active spaces here: https://github.com/codespaces and then click the "..." 3 dots to stop any of them.

### RESEARCH: 
TOPICS FOR HACKATHON: 
1. Forecasting 
Forecasting uses available information to estimate what might happen next. An early example of  organized public forecasting came in 1861, when Robert FitzRoy’s team began issuing daily  weather forecasts in Britain. Telegraph reports let forecasters compare conditions across  locations and see how weather systems were moving. Today, a forecast might come from a  physics simulation, a statistical model, or machine learning. A weather model, for example, can  run several simulations with slightly different starting conditions to estimate how likely rain is.  
2. Transformers 
Vaswani and colleagues introduced the Transformer in 2017 in a paper about machine  translation. Its central mechanism is attention, which lets a model weigh how relevant other  tokens are when forming a representation of a given token. In “The dog chased the ball because  it was excited,” attention can help connect “it” with “dog.” In a text-generating Transformer, the  model uses the tokens it has already seen to estimate the probabilities of possible next tokens,  selects one, and repeats.  
3. Statistical mechanics of complex networks 
Statistical mechanics originally used probability to explain how large groups of particles produce  effects like temperature and pressure. Researchers later brought a similar approach to  networks. In 1998, Watts and Strogatz showed how networks can have tightly connected local  groups and still have short paths between distant points. In 1999, Barabási and Albert showed  how a growing network can develop hubs when new nodes tend to connect to already well connected ones. These models help explain how local connections can give rise to patterns  across a whole network.  
4. Decision trees 
A decision tree makes a prediction by asking a sequence of questions. The branches  correspond to different answers, and the endpoint gives the prediction. In 1986, J. Ross Quinlan  published a description of ID3, an influential method for learning trees from examples. During  training, ID3 looks for a question that best separates the known categories, then repeats the  process within each branch. A spam filter could first ask whether a message contains a link,  then ask whether the sender is known.  
5. Ant 
Ant colony optimization, a family of methods developed in the 1990s. It takes inspiration from  ants leaving chemical trails that influence where other ants travel. In the algorithm, simulated 
ants build possible solutions, such as routes through several cities. Better routes receive more  virtual pheromone, making future ants more likely to reuse parts of them. The pheromone  gradually fades, which helps the algorithm keep exploring. It can find good routes without  promising the best possible one. 
The abbreviated label leaves room for another interpretation. Langton’s ant is a grid simulation  from the 1980s in which an agent turns according to the color of its current square, flips that  color, and moves forward. It illustrates how simple rules can generate surprisingly complex  patterns.  
6. Machine-learned ranking 
Machine-learned ranking became an important part of search research in the 2000s. The idea is  to learn how to order results from examples, such as pages that people have judged more or  less relevant to a search. Given a new query, the model can use clues like whether the search  terms appear in a page’s title or how closely the page matches the query’s meaning. It scores  the candidates and puts the strongest matches first. The quality of the ranking depends in part  on what the training data treats as a good result.  
7. Computational linguistics 
Computational linguistics studies how computers can represent, analyze, and generate human  language. An early milestone was the 1954 Georgetown–IBM demonstration, which translated a  limited set of Russian sentences into English using a small vocabulary and explicit rules. The  field later developed statistical and neural methods that learn patterns from text. One challenge  is ambiguity. A system translating “I went to the bank” needs context to decide whether “bank”  refers to a financial institution or the side of a river.  
8. Ranking 
Ranking orders items according to a criterion such as relevance, popularity, or importance. One  influential example is PageRank, described by Sergey Brin and Larry Page in 1998. It used  hyperlinks to estimate the importance of web pages. A link from a page that was itself important  contributed more than a link from a less important page. One way to picture it is to imagine  someone randomly following links and occasionally jumping to a new page. The pages where  that person would spend more time receive higher PageRank scores.  
9. Classification 
Classification puts an example into a category that has already been defined. People have  classified things for centuries, and twentieth-century statistics and computing made it possible to  train classifiers from examples. A spam classifier sees messages labeled spam or not spamduring training. It learns which features tend to go with each label and uses those patterns to 
label new messages. Its mistakes can come from patterns it learned correctly in the training  data that happen to be misleading in a new case.  
10. Search 
In computing, search means looking for a target in a collection or exploring possible states to  find a solution. During the twentieth century, it became a basic problem in computer science and  information retrieval. Binary search is one example. On a sorted list, check the middle item and  use its value to rule out half the remaining list. A web search engine handles a different kind of  search. It uses an index to find candidate pages, then ranks them for the query.  
11. Traditional forecasting 
Traditional forecasting draws on established statistical methods and human judgment. In  twentieth-century business and economic forecasting, analysts often worked with  measurements over time, such as monthly sales. A moving average smooths out short-term  swings by averaging recent observations. More elaborate methods estimate trends and  seasonal patterns separately. For example, next December’s sales might be estimated using  both the recent growth rate and the size of past December spikes. 
12. Clustering 
Clustering groups examples by similarity without requiring someone to label them in advance. A  widely used approach, k-means, took shape in the mid-twentieth century. You choose how  many groups you want, and the algorithm starts with that many centers. It assigns each point to  its nearest center, moves each center to the average location of its assigned points, and  repeats. For example, documents can be grouped using patterns in the words they contain. The  result depends on how you represent the documents and measure similarity.  
13. Compression 
Compression represents data with fewer bits. Shannon’s 1948 work explained why predictable  data can often be encoded more efficiently. Lossless compression, as in a ZIP archive, lets you  recover the original exactly. It might store a short reference each time a pattern repeats. Lossycompression, used in formats like JPEG, saves more space by discarding some detail. In a  photo, you might barely notice what was removed at a high quality setting, then see visible  artifacts as compression increases.  
14. ECC: Error-correcting codes 
Richard Hamming published a foundational paper on error-detecting and error-correcting codes  in 1950. The idea is to add carefully chosen extra bits before storing or sending data. When the  data arrives, the receiver checks whether it still follows the rules of the code. In a basic 
Hamming code, the pattern of failed checks identifies which bit flipped, so the receiver can fix it.  The extra bits let a system recover from certain errors without asking for the data again.  
15. Random walk 
A random walk is a path made of a series of randomly chosen steps. Karl Pearson posed a  famous version in 1905 involving a walker who repeatedly steps in a random direction. A simple  version uses a coin flip to decide whether to move one step left or right. Any single path is  unpredictable, but you can calculate patterns across many walks, such as how far walkers  typically stray from where they started. Random walks also work on networks. Each step can  consist of picking a neighboring node to visit.  
16. Entropy 
In information theory, entropy measures the average uncertainty of an outcome before you  see it. Shannon formalized this idea in 1948. A fair coin has one bit of entropy per flip because  its two outcomes are equally likely. A coin that almost always lands heads has lower entropy  because there is less uncertainty about what will happen. That predictability matters for  compression. A long sequence from the biased coin can generally be encoded using fewer bits  per flip.  
17. Information theory 
Shannon’s 1948 paper established a mathematical framework for studying how messages are  encoded and transmitted. Picture someone speaking over a noisy phone line. There is a source  producing the message, a channel carrying it, and a receiver trying to recover it. Information  theory asks how compactly you can represent the message and how fast you can send it with a  low risk of error. Entropy measures uncertainty at the source, while channel capacity describes the limit on reliable transmission through the channel.  
18. SNA: Social network analysis 
Social network analysis studies relationships by representing people or organizations as nodesand their connections as edges. In the 1930s, Jacob Moreno used diagrams called sociogramsto show social relationships within groups. Today, researchers can use network measures to  identify tightly connected groups or people who link otherwise separate communities. Someone  with only a few connections might still be important if they connect two groups that rarely  interact.  
19. Markov chains 
Andrey Markov developed the mathematics behind these chains in the early twentieth century to  study sequences in which outcomes depend on one another. A Markov chain models movement  between states using probabilities that depend on the current state. A simple weather chain 
could use one set of probabilities for tomorrow if today is sunny and another set if today is rainy.  Repeating those transitions lets you estimate the probabilities several days ahead. A random  walk is one example of a Markov chain.  
20. Sorting 
Sorting puts records in an order, such as names alphabetically or prices from lowest to highest.  As computers began processing larger collections of data, the efficiency of sorting became a  major concern. In 1962, Tony Hoare published quicksort, which chooses a pivot, separates  elements according to how they compare with that pivot, and sorts the smaller groups using the  same procedure. Sorting also makes other tasks easier. Once an array is sorted, binary search  can discard half of the remaining candidates at each step.  
21. Linear algebra 
Linear algebra grew out of the need to solve systems of equations. Methods for working through  systems appeared in ancient mathematics, and nineteenth-century mathematicians developed  modern ideas about matrices and vector spaces. A matrix can keep track of the coefficients in a  system or represent an operation like rotating points on a screen. The same mathematical  machinery lets a game engine rotate a 3D object and a machine-learning model transform  thousands of numerical inputs at once.  
22. Bayesian interpretation of probability 
Thomas Bayes’s work on reasoning from observed outcomes was published posthumously in  1763, and Pierre-Simon Laplace extended this approach. In Bayesian reasoning, you start with  a prior, which expresses what you know or assume before seeing new evidence. You then ask  how likely that evidence would be under different possibilities and update to a posterior. If  you’re trying to figure out whether a coin is biased, eight heads in ten flips should increase your  suspicion. How much your suspicion increases depends on what you assumed about the coin  beforehand.  
23. Fourier transform 
Joseph Fourier’s early nineteenth-century work on heat showed the power of representing  complicated patterns with simpler waves. The Fourier transform extends that idea by expressing  a signal in terms of the frequencies it contains. A recording of a piano chord looks like one  complicated waveform over time. In a frequency representation, you can see peaks  corresponding to the notes and their harmonics. That makes it easier to do things like identify  and remove an unwanted hum.  
24. Gaussian distribution
The Gaussian or normal distribution developed through work by Abraham de Moivre, Laplace,  and Carl Friedrich Gauss. One important application was modeling errors in repeated  measurements. Its familiar bell curve is symmetric, with smaller deviations from the center  occurring more often than large ones. The mean locates the center, and the standard  deviation describes the spread. For example, repeated measurements of the same length may  cluster around one value if many small, independent sources of error affect the readings.  
25. Laplace transform 
Named after Pierre-Simon Laplace, the Laplace transform became a standard tool for solving  equations about how systems change over time. It converts a function of time into a function of  a new variable. In that form, differentiation can turn into multiplication with an adjustment for the  starting conditions. An engineer can use it to turn a differential equation describing a circuit into  an algebra problem, solve that problem, then use the inverse transform to find how the voltage  changes over time. 
26. Statistical inference 
Statistical inference uses observations from a sample to draw conclusions about a larger  population or an underlying process. Laplace and Gauss helped develop early methods for  reasoning from noisy measurements. Later work formalized tools such as confidence intervals  and hypothesis tests. In a campus survey, for example, inference lets you estimate how  common an opinion is beyond the students you interviewed. The estimate depends on how the  sample was collected. A large survey taken from one class can still misrepresent the campus.  
27. Graph theory 
A classic starting point for graph theory is Leonhard Euler’s eighteenth-century study of the  Seven Bridges of Königsberg. The puzzle asked whether a person could cross each bridge  exactly once. Euler reduced the geography to land areas and their connections. In today’s  terms, the land areas are vertices and the bridges are edges. This abstraction lets the same  mathematical tools answer questions about routes, social networks, and which courses must be  taken before others.  
28. Probability 
Probability gives a numerical way to describe uncertainty. A landmark in its development was  the 1654 correspondence between Blaise Pascal and Pierre de Fermat about how to divide the  stakes fairly when a game ends early. In a simple case where every possible outcome is equally  likely, the probability of an event is the number of outcomes that satisfy it divided by the total  number of outcomes. More general models can assign different probabilities to different  outcomes, like the faces of a weighted die.  
29. Optimization
Optimization means finding the best available choice according to a specified goal. Early  mathematical approaches used geometry and calculus to study maxima and minima. Modern  applications often involve many variables and restrictions. A delivery company might try to  minimize driving time while satisfying delivery windows and truck capacities. The driving time is  the objective, and the limits are the constraints. A different objective, such as minimizing fuel  use, can produce a different route even when the constraints stay the same.  
30. Calculus 
Isaac Newton and Gottfried Wilhelm Leibniz independently developed systematic versions of  calculus in the late seventeenth century, building on earlier work on motion, tangents, and  areas. Derivatives describe instantaneous change. If you know a ball’s position as a function of  time, its derivative gives its velocity. Integrals describe accumulation. Integrating the velocity  over a time interval gives the ball’s displacement. The fundamental theorem of calculus  connects these two operations.  
31. Classical mechanics 
Classical mechanics describes how objects move under forces. Newton’s 1687 Principia unified  motion on Earth and in the heavens within one mathematical framework. A simple example  uses F=ma to get an object’s acceleration from the net force and its mass. If you know a ball’s  position and velocity when it leaves a bowler’s hand, you can model its flight under gravity and  add effects such as air resistance or a bounce as needed.  
32. Cartesian geometry 
In the seventeenth century, René Descartes helped establish the connection between algebra  and geometry. Cartesian geometry describes points with coordinates such as (x,y) and shapes  with equations. For example, x^2+y^2=25 describes all points five units from the origin. If you  want to find where a line crosses that circle, you can solve two equations together. That  connection between equations and shapes is central to graphing functions, computer graphics,  and mapping.  
33. Games of chance 
Dice, cards, and wagers gave mathematicians concrete problems to think about before  probability became a formal field. In the seventeenth century, Pascal and Fermat used a  gambling dispute to reason about what could happen in the unfinished rounds of a game. One  way to analyze a wager is to calculate its expected value. Multiply each possible net gain or  loss by its probability, then add those amounts. The result tells you the average gain or loss  you’d expect per play over many repetitions.  
34. Median
The median is the middle of an ordered dataset. Francis Galton helped popularize it in  nineteenth-century statistics. With an odd number of values, take the middle item. With an even  number, the usual convention is to average the two middle items. For the values 2, 4, 6, 8, and  100, the median is 6. That extreme value has little influence on the median, which is why it  works well when describing typical rents, incomes, or home prices.  
35. Arithmetic mean 
The arithmetic mean is the familiar average. It became particularly important when astronomers  and other scientists needed to combine repeated measurements affected by observational  error. To calculate it, add the values and divide by how many there are. For 2, 4, 6, 8, and 100,  the mean is 24. Because each value contributes its full amount to the total, a very large or small  value can pull the mean away from where most observations lie.  
36. Vector space 
The abstract idea of a vector space took shape in the nineteenth century, with early work by  Giuseppe Peano in 1888. A vector space is a collection of objects you can add together and  multiply by numbers while staying inside that collection and following standard algebraic rules.  Ordinary arrows in a plane are one example. Polynomials of degree at most two are another,  because adding them or multiplying them by a number still gives a polynomial in the same  collection. This is why linear algebra can apply to both geometric objects and things like text  represented by lists of numbers.  
37. Regression 
Regression grew out of methods for fitting equations to observations. The term became  associated with Francis Galton’s nineteenth-century studies of hereditary traits and his  description of regression toward the mean. Today, a simple linear regression might use past  sales to estimate how home price changes with square footage. In ordinary least squares, the  model chooses the line that minimizes the sum of the squared differences between observed  prices and predicted prices. You can then use the line to estimate the price of a home of a given  size.  
38. Correlation 
Correlation measures how two variables vary together. Modern statistical treatments grew out of  work by Francis Galton and Karl Pearson in the late nineteenth century. Pearson’s correlation  coefficient ranges from -1 to 1 and measures the strength and direction of a linear relationship.  Ice cream sales and swimming attendance might have a positive correlation because both tend  to rise when it’s hot. That shared influence illustrates why a correlation alone cannot establish  that one variable causes the other. 


### Works Cited 
Bakker, Arthur. “The Early History of Average Values and Implications for Education.” Journal of  Statistics Education, vol. 11, no. 1, 2003. https://doi.org/10.1080/10691898.2003.11910694. 
Barabási, Albert-László, and Réka Albert. “Emergence of Scaling in Random Networks.”  Science, vol. 286, no. 5439, 1999, pp. 509–12. https://doi.org/10.1126/science.286.5439.509. 
Brin, Sergey, and Lawrence Page. “The Anatomy of a Large-Scale Hypertextual Web Search  Engine.” Computer Networks and ISDN Systems, vol. 30, nos. 1–7, 1998, pp. 107–17.  https://doi.org/10.1016/S0169-7552(98)00110-X . 
Crawford, Kate, and Vladan Joler. Calculating Empires: A Genealogy of Technology and Power  Since 1500. 2023, www.calculatingempires.net . 
Dorigo, Marco, et al. “Ant System: Optimization by a Colony of Cooperating Agents.” IEEE  Transactions on Systems, Man, and Cybernetics, Part B (Cybernetics), vol. 26, no. 1, 1996, pp.  29–41. https://doi.org/10.1109/3477.484436 . 
Garvin, Paul L. “The Georgetown-IBM Experiment of 1954: An Evaluation in Retrospect.” 1967.  ACL Anthology, aclanthology.org/www.mt-archive.info/50/Garvin-1967.pdf . 
Gorroochurn, Prakash. Classic Topics on the History of Modern Mathematical Statistics: From  Laplace to More Recent Times. Wiley, 2016. https://doi.org/10.1002/9781119127963 . 
Hamming, Richard W. “Error Detecting and Error Correcting Codes.” The Bell System Technical  Journal, vol. 29, no. 2, 1950, pp. 147–60. https://doi.org/10.1002/j.1538-7305.1950.tb00463.x. 
Hoare, C. A. R. “Quicksort.” The Computer Journal, vol. 5, no. 1, 1962, pp. 10–16.  https://doi.org/10.1093/comjnl/5.1.10 . 
Hyndman, Rob J., and George Athanasopoulos. Forecasting: Principles and Practice. 3rd ed.,  OTexts, 2021, otexts.com/fpp3 . 
“Laplace Transform: Solving Initial Value Problems.” MIT OpenCourseWare, Massachusetts  Institute of Technology, ocw.mit.edu . 
Manning, Christopher D., et al. Introduction to Information Retrieval. Cambridge UP, 2008,  nlp.stanford.edu/IR-book . 
Met Office. From Sorcery to Supercomputers. 2023, www.metoffice.gov.uk . 
Moreno, Jacob L. Who Shall Survive? A New Approach to the Problem of Human Interrelations. Nervous and Mental Disease Publishing Co., 1934. AGRIS .
O’Connor, J. J., and E. F. Robertson. “Andrei Andreyevich Markov.” MacTutor History of  Mathematics, University of St Andrews, mathshistory.st-andrews.ac.uk/Biographies/Markov. 
“History Overview.” MacTutor History of Mathematics, University of St Andrews, mathshistory.st andrews.ac.uk/HistTopics/History_overview . 
“Joseph Fourier.” MacTutor History of Mathematics, University of St Andrews, mathshistory.st andrews.ac.uk/Biographies/Fourier . 
“Leonhard Euler.” MacTutor History of Mathematics, University of St Andrews, mathshistory.st andrews.ac.uk/Biographies/Euler . 
Pearson, Karl. “The Problem of the Random Walk.” Nature, vol. 72, 1905, p. 294.  https://doi.org/10.1038/072294b0 . 
Quinlan, J. Ross. “Induction of Decision Trees.” Machine Learning, vol. 1, 1986, pp. 81–106.  https://doi.org/10.1007/BF00116251 . 
Shannon, Claude E. “A Mathematical Theory of Communication.” The Bell System Technical  Journal, vol. 27, 1948, pp. 379–423 and 623–56. Harvard University . 
Swetz, Frank J. “Mathematical Treasure: Peano’s Vector Calculus.” Convergence, Mathematical  Association of America, June 2017, old.maa.org . 
Todhunter, Isaac. A History of the Mathematical Theory of Probability: From the Time of Pascal  to That of Laplace. 1865. Cambridge UP, 2015. Cambridge Core . 
Vaswani, Ashish, et al. “Attention Is All You Need.” Advances in Neural Information Processing  Systems, vol. 30, 2017. arXiv . 
Watts, Duncan J., and Steven H. Strogatz. “Collective Dynamics of ‘Small-World’ Networks.”  Nature, vol. 393, 1998, pp. 440–42. https://doi.org/10.1038/30918 . 
Weisstein, Eric W. “Langton’s Ant.” MathWorld, Wolfram Research,  
mathworld.wolfram.com/LangtonsAnt.html . 
// used AI to help appropriately format sources
