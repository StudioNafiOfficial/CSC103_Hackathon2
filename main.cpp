#include "Milestone.h"
#include "Card.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <raylib.h>
#include <string>
#include <vector>

using namespace std;

int main() {
    // screen dimensions
    const int screenWidth = 1440;
    const int screenHeight = 1080;

    // initialize window and set fps
    InitWindow(screenWidth, screenHeight, "Timeline Scroll - Raylib");
    SetTargetFPS(60);

    // milestone years
    const vector<int> years = {
        2025, 2012, 2000, 1975, 1950, 1925,
        1900, 1850, 1800, 1700, 1600, 1500
    };

    // vector of milestone years
    vector<Milestone> milestones;

    // making sure the years are positioned nicely
    float currentY = 220.0f;
    const float pixelsPerYear = 4.0f;
    const float minGap = 140.0f;

    // positioning for each milestone
    for (size_t i = 0; i < years.size(); ++i) {
        if (i > 0) { // first milestone should just be at y=220
            float yearDelta = static_cast<float>(years[i - 1] - years[i]);
            float spacing = max(minGap, yearDelta * pixelsPerYear);
            currentY += spacing;
        }
        milestones.push_back({years[i], currentY, 36.0f});
    }

    // Specific hand-picked card positions: {worldX, worldY, radius, text}
    // Gemini was used to paste in the information
    vector<Card> cards = {
        {720.0f,  220.0f, 34.0f, "Forecasting", "Forecasting uses available information to estimate what might happen next. An early example of organized public forecasting came in 1861, when Robert FitzRoy's team began issuing daily weather forecasts in Britain. Telegraph reports let forecasters compare conditions across locations and see how weather systems were moving. Today, a forecast might come from a physics simulation, a statistical model, or machine learning. A weather model, for example, can run several simulations with slightly different starting conditions to estimate how likely rain is.", false},
        {540.0f,  300.0f, 30.0f, "Transformers", "Vaswani and colleagues introduced the Transformer in 2017 in a paper about machine translation. Its central mechanism is attention, which lets a model weigh how relevant other tokens are when forming a representation of a given token. In \"The dog chased the ball because it was excited,\" attention can help connect \"it\" with \"dog.\" In a text-generating Transformer, the model uses the tokens it has already seen to estimate the probabilities of possible next tokens, selects one, and repeats.", false},
        {930.0f,  370.0f, 40.0f, "Statistical mechanics of complex networks", "Statistical mechanics originally used probability to explain how large groups of particles produce effects like temperature and pressure. Researchers later brought a similar approach to networks. In 1998, Watts and Strogatz showed how networks can have tightly connected local groups and still have short paths between distant points. In 1999, Barabasi and Albert showed how a growing network can develop hubs when new nodes tend to connect to already well connected ones. These models help explain how local connections can give rise to patterns across a whole network.", false},
        {650.0f,  445.0f, 28.0f, "Decision trees", "A decision tree makes a prediction by asking a sequence of questions. The branches correspond to different answers, and the endpoint gives the prediction. In 1986, J. Ross Quinlan published a description of ID3, an influential method for learning trees from examples. During training, ID3 looks for a question that best separates the known categories, then repeats the process within each branch. A spam filter could first ask whether a message contains a link, then ask whether the sender is known.", false},
        {860.0f,  520.0f, 36.0f, "Ant", "Ant colony optimization, a family of methods developed in the 1990s. It takes inspiration from ants leaving chemical trails that influence where other ants travel. In the algorithm, simulated ants build possible solutions, such as routes through several cities. Better routes receive more virtual pheromone, making future ants more likely to reuse parts of them. The pheromone gradually fades, which helps the algorithm keep exploring. It can find good routes without promising the best possible one. The abbreviated label leaves room for another interpretation. Langton's ant is a grid simulation from the 1980s in which an agent turns according to the color of its current square, flips that color, and moves forward. It illustrates how simple rules can generate surprisingly complex patterns.", false},
        {480.0f,  595.0f, 32.0f, "Machine-learned ranking", "Machine-learned ranking became an important part of search research in the 2000s. The idea is to learn how to order results from examples, such as pages that people have judged more or less relevant to a search. Given a new query, the model can use clues like whether the search terms appear in a page's title or how closely the page matches the query's meaning. It scores the candidates and puts the strongest matches first. The quality of the ranking depends in part on what the training data treats as a good result.", false},
        {980.0f,  670.0f, 38.0f, "Computational linguistics", "Computational linguistics studies how computers can represent, analyze, and generate human language. An early milestone was the 1954 Georgetown-IBM demonstration, which translated a limited set of Russian sentences into English using a small vocabulary and explicit rules. The field later developed statistical and neural methods that learn patterns from text. One challenge is ambiguity. A system translating \"I went to the bank\" needs context to decide whether \"bank\" refers to a financial institution or the side of a river.", false},
        {720.0f,  745.0f, 42.0f, "Ranking", "Ranking orders items according to a criterion such as relevance, popularity, or importance. One influential example is PageRank, described by Sergey Brin and Larry Page in 1998. It used hyperlinks to estimate the importance of web pages. A link from a page that was itself important contributed more than a link from a less important page. One way to picture it is to imagine someone randomly following links and occasionally jumping to a new page. The pages where that person would spend more time receive higher PageRank scores.", false},
        {560.0f,  820.0f, 30.0f, "Classification", "Classification puts an example into a category that has already been defined. People have classified things for centuries, and twentieth-century statistics and computing made it possible to train classifiers from examples. A spam classifier sees messages labeled spam or not spam during training. It learns which features tend to go with each label and uses those patterns to label new messages. Its mistakes can come from patterns it learned correctly in the training data that happen to be misleading in a new case.", false},
        {890.0f,  895.0f, 35.0f, "Search", "In computing, search means looking for a target in a collection or exploring possible states to find a solution. During the twentieth century, it became a basic problem in computer science and information retrieval. Binary search is one example. On a sorted list, check the middle item and use its value to rule out half the remaining list. A web search engine handles a different kind of search. It uses an index to find candidate pages, then ranks them for the query.", false},
        {640.0f,  970.0f, 32.0f, "Traditional forecasting", "Traditional forecasting draws on established statistical methods and human judgment. In twentieth-century business and economic forecasting, analysts often worked with measurements over time, such as monthly sales. A moving average smooths out short-term swings by averaging recent observations. More elaborate methods estimate trends and seasonal patterns separately. For example, next December's sales might be estimated using both the recent growth rate and the size of past December spikes.", false},
        {940.0f, 1045.0f, 38.0f, "Clustering", "Clustering groups examples by similarity without requiring someone to label them in advance. A widely used approach, k-means, took shape in the mid-twentieth century. You choose how many groups you want, and the algorithm starts with that many centers. It assigns each point to its nearest center, moves each center to the average location of its assigned points, and repeats. For example, documents can be grouped using patterns in the words they contain. The result depends on how you represent the documents and measure similarity.", false},
        {510.0f, 1120.0f, 28.0f, "Compression", "Compression represents data with fewer bits. Shannon's 1948 work explained why predictable data can often be encoded more efficiently. Lossless compression, as in a ZIP archive, lets you recover the original exactly. It might store a short reference each time a pattern repeats. Lossy compression, used in formats like JPEG, saves more space by discarding some detail. In a photo, you might barely notice what was removed at a high quality setting, then see visible artifacts as compression increases.", false},
        {760.0f, 1195.0f, 40.0f, "ECC: Error-correcting codes", "Richard Hamming published a foundational paper on error-detecting and error-correcting codes in 1950. The idea is to add carefully chosen extra bits before storing or sending data. When the data arrives, the receiver checks whether it still follows the rules of the code. In a basic Hamming code, the pattern of failed checks identifies which bit flipped, so the receiver can fix it. The extra bits let a system recover from certain errors without asking for the data again.", false},
        {960.0f, 1270.0f, 34.0f, "Random walk", "A random walk is a path made of a series of randomly chosen steps. Karl Pearson posed a famous version in 1905 involving a walker who repeatedly steps in a random direction. A simple version uses a coin flip to decide whether to move one step left or right. Any single path is unpredictable, but you can calculate patterns across many walks, such as how far walkers typically stray from where they started. Random walks also work on networks. Each step can consist of picking a neighboring node to visit.", false},
        {600.0f, 1345.0f, 36.0f, "Entropy", "In information theory, entropy measures the average uncertainty of an outcome before you see it. Shannon formalized this idea in 1948. A fair coin has one bit of entropy per flip because its two outcomes are equally likely. A coin that almost always lands heads has lower entropy because there is less uncertainty about what will happen. That predictability matters for compression. A long sequence from the biased coin can generally be encoded using fewer bits per flip.", false},
        {830.0f, 1420.0f, 30.0f, "Information theory", "Shannon's 1948 paper established a mathematical framework for studying how messages are encoded and transmitted. Picture someone speaking over a noisy phone line. There is a source producing the message, a channel carrying it, and a receiver trying to recover it. Information theory asks how compactly you can represent the message and how fast you can send it with a low risk of error. Entropy measures uncertainty at the source, while channel capacity describes the limit on reliable transmission through the channel.", false},
        {470.0f, 1495.0f, 38.0f, "SNA: Social network analysis", "Social network analysis studies relationships by representing people or organizations as nodes and their connections as edges. In the 1930s, Jacob Moreno used diagrams called sociograms to show social relationships within groups. Today, researchers can use network measures to identify tightly connected groups or people who link otherwise separate communities. Someone with only a few connections might still be important if they connect two groups that rarely interact.", false},
        {720.0f, 1570.0f, 42.0f, "Markov chains", "Andrey Markov developed the mathematics behind these chains in the early twentieth century to study sequences in which outcomes depend on one another. A Markov chain models movement between states using probabilities that depend on the current state. A simple weather chain could use one set of probabilities for tomorrow if today is sunny and another set if today is rainy. Repeating those transitions lets you estimate the probabilities several days ahead. A random walk is one example of a Markov chain.", false},
        {950.0f, 1645.0f, 32.0f, "Sorting", "Sorting puts records in an order, such as names alphabetically or prices from lowest to highest. As computers began processing larger collections of data, the efficiency of sorting became a major concern. In 1962, Tony Hoare published quicksort, which chooses a pivot, separates elements according to how they compare with that pivot, and sorts the smaller groups using the same procedure. Sorting also makes other tasks easier. Once an array is sorted, binary search can discard half of the remaining candidates at each step.", false},
        {580.0f, 1720.0f, 34.0f, "Linear algebra", "Linear algebra grew out of the need to solve systems of equations. Methods for working through systems appeared in ancient mathematics, and nineteenth-century mathematicians developed modern ideas about matrices and vector spaces. A matrix can keep track of the coefficients in a system or represent an operation like rotating points on a screen. The same mathematical machinery lets a game engine rotate a 3D object and a machine-learning model transform thousands of numerical inputs at once.", false},
        {840.0f, 1795.0f, 36.0f, "Bayesian interpretation of probability", "Thomas Bayes's work on reasoning from observed outcomes was published posthumously in 1763, and Pierre-Simon Laplace extended this approach. In Bayesian reasoning, you start with a prior, which expresses what you know or assume before seeing new evidence. You then ask how likely that evidence would be under different possibilities and update to a posterior. If you're trying to figure out whether a coin is biased, eight heads in ten flips should increase your suspicion. How much your suspicion increases depends on what you assumed about the coin beforehand.", false},
        {670.0f, 1870.0f, 28.0f, "Fourier transform", "Joseph Fourier's early nineteenth-century work on heat showed the power of representing complicated patterns with simpler waves. The Fourier transform extends that idea by expressing a signal in terms of the frequencies it contains. A recording of a piano chord looks like one complicated waveform over time. In a frequency representation, you can see peaks corresponding to the notes and their harmonics. That makes it easier to do things like identify and remove an unwanted hum.", false},
        {920.0f, 1945.0f, 40.0f, "Gaussian distribution", "The Gaussian or normal distribution developed through work by Abraham de Moivre, Laplace, and Carl Friedrich Gauss. One important application was modeling errors in repeated measurements. Its familiar bell curve is symmetric, with smaller deviations from the center occurring more often than large ones. The mean locates the center, and the standard deviation describes the spread. For example, repeated measurements of the same length may cluster around one value if many small, independent sources of error affect the readings.", false},
        {500.0f, 2020.0f, 35.0f, "Laplace transform", "Named after Pierre-Simon Laplace, the Laplace transform became a standard tool for solving equations about how systems change over time. It converts a function of time into a function of a new variable. In that form, differentiation can turn into multiplication with an adjustment for the starting conditions. An engineer can use it to turn a differential equation describing a circuit into an algebra problem, solve that problem, then use the inverse transform to find how the voltage changes over time.", false},
        {750.0f, 2095.0f, 32.0f, "Statistical inference", "Statistical inference uses observations from a sample to draw conclusions about a larger population or an underlying process. Laplace and Gauss helped develop early methods for reasoning from noisy measurements. Later work formalized tools such as confidence intervals and hypothesis tests. In a campus survey, for example, inference lets you estimate how common an opinion is beyond the students you interviewed. The estimate depends on how the sample was collected. A large survey taken from one class can still misrepresent the campus.", false},
        {970.0f, 2170.0f, 38.0f, "Graph theory", "A classic starting point for graph theory is Leonhard Euler's eighteenth-century study of the Seven Bridges of Konigsberg. The puzzle asked whether a person could cross each bridge exactly once. Euler reduced the geography to land areas and their connections. In today's terms, the land areas are vertices and the bridges are edges. This abstraction lets the same mathematical tools answer questions about routes, social networks, and which courses must be taken before others.", false},
        {610.0f, 2245.0f, 30.0f, "Probability", "Probability gives a numerical way to describe uncertainty. A landmark in its development was the 1654 correspondence between Blaise Pascal and Pierre de Fermat about how to divide the stakes fairly when a game ends early. In a simple case where every possible outcome is equally likely, the probability of an event is the number of outcomes that satisfy it divided by the total number of outcomes. More general models can assign different probabilities to different outcomes, like the faces of a weighted die.", false},
        {860.0f, 2320.0f, 36.0f, "Optimization", "Optimization means finding the best available choice according to a specified goal. Early mathematical approaches used geometry and calculus to study maxima and minima. Modern applications often involve many variables and restrictions. A delivery company might try to minimize driving time while satisfying delivery windows and truck capacities. The driving time is the objective, and the limits are the constraints. A different objective, such as minimizing fuel use, can produce a different route even when the constraints stay the same.", false},
        {530.0f, 2395.0f, 34.0f, "Calculus", "Isaac Newton and Gottfried Wilhelm Leibniz independently developed systematic versions of calculus in the late seventeenth century, building on earlier work on motion, tangents, and areas. Derivatives describe instantaneous change. If you know a ball's position as a function of time, its derivative gives its velocity. Integrals describe accumulation. Integrating the velocity over a time interval gives the ball's displacement. The fundamental theorem of calculus connects these two operations.", false},
        {720.0f, 2465.0f, 42.0f, "Classical mechanics", "Classical mechanics describes how objects move under forces. Newton's 1687 Principia unified motion on Earth and in the heavens within one mathematical framework. A simple example uses F=ma to get an object's acceleration from the net force and its mass. If you know a ball's position and velocity when it leaves a bowler's hand, you can model its flight under gravity and add effects such as air resistance or a bounce as needed.", false},
        {940.0f, 2515.0f, 32.0f, "Cartesian geometry", "In the seventeenth century, Rene Descartes helped establish the connection between algebra and geometry. Cartesian geometry describes points with coordinates such as (x,y) and shapes with equations. For example, x^2+y^2=25 describes all points five units from the origin. If you want to find where a line crosses that circle, you can solve two equations together. That connection between equations and shapes is central to graphing functions, computer graphics, and mapping.", false},
        {620.0f, 2560.0f, 38.0f, "Games of chance", "Dice, cards, and wagers gave mathematicians concrete problems to think about before probability became a formal field. In the seventeenth century, Pascal and Fermat used a gambling dispute to reason about what could happen in the unfinished rounds of a game. One way to analyze a wager is to calculate its expected value. Multiply each possible net gain or loss by its probability, then add those amounts. The result tells you the average gain or loss you'd expect per play over many repetitions.", false},
        {870.0f, 2595.0f, 30.0f, "Median", "The median is the middle of an ordered dataset. Francis Galton helped popularize it in nineteenth-century statistics. With an odd number of values, take the middle item. With an even number, the usual convention is to average the two middle items. For the values 2, 4, 6, 8, and 100, the median is 6. That extreme value has little influence on the median, which is why it works well when describing typical rents, incomes, or home prices.", false},
        {490.0f, 2625.0f, 36.0f, "Arithmetic mean", "The arithmetic mean is the familiar average. It became particularly important when astronomers and other scientists needed to combine repeated measurements affected by observational error. To calculate it, add the values and divide by how many there are. For 2, 4, 6, 8, and 100, the mean is 24. Because each value contributes its full amount to the total, a very large or small value can pull the mean away from where most observations lie.", false},
        {760.0f, 2650.0f, 34.0f, "Vector space", "The abstract idea of a vector space took shape in the nineteenth century, with early work by Giuseppe Peano in 1888. A vector space is a collection of objects you can add together and multiply by numbers while staying inside that collection and following standard algebraic rules. Ordinary arrows in a plane are one example. Polynomials of degree at most two are another, because adding them or multiplying them by a number still gives a polynomial in the same collection. This is why linear algebra can apply to both geometric objects and things like text represented by lists of numbers.", false},
        {960.0f, 2740.0f, 40.0f, "Regression", "Regression grew out of methods for fitting equations to observations. The term became associated with Francis Galton's nineteenth-century studies of hereditary traits and his description of regression toward the mean. Today, a simple linear regression might use past sales to estimate how home price changes with square footage. In ordinary least squares, the model chooses the line that minimizes the sum of the squared differences between observed prices and predicted prices. You can then use the line to estimate the price of a home of a given size.", false},
        {590.0f, 2830.0f, 28.0f, "Correlation", "Correlation measures how two variables vary together. Modern statistical treatments grew out of work by Francis Galton and Karl Pearson in the late nineteenth century. Pearson's correlation coefficient ranges from -1 to 1 and measures the strength and direction of a linear relationship. Ice cream sales and swimming attendance might have a positive correlation because both tend to rise when it's hot. That shared influence illustrates why a correlation alone cannot establish that one variable causes the other.", false}
    };

    // set up our camera
    Camera2D camera = {0};
    camera.target = {0.0f, 0.0f};
    camera.offset = {0.0f, 0.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    // scroll boundaries
    const float minScrollY = 0.0f;
    float lowestContentY = milestones.back().worldY;
    for (const Card& card : cards) {
        lowestContentY = max(lowestContentY, card.worldY);
    }
    const float maxScrollY = max(minScrollY, lowestContentY - (screenHeight * 0.5f));

    // getting where we want to scroll to
    float scrollTargetY = minScrollY;
    const float scrollSpeed = 95.0f;
    const float smoothness = 12.0f;

    Vector2 mousePoint = {0, 0};

    int activeCardIndex = -1; // -1 means no description box is currently shown

    while (!WindowShouldClose()) {
        // getting time between each frame
        float dt = GetFrameTime();


        // calculating our scroll
        float wheel = GetMouseWheelMove();
        if (wheel != 0.0f) {
            scrollTargetY -= wheel * scrollSpeed;
        }
        if (IsKeyDown(KEY_DOWN)) {
            scrollTargetY += scrollSpeed * 8.0f * dt;
        }
        if (IsKeyDown(KEY_UP)) {
            scrollTargetY -= scrollSpeed * 8.0f * dt;
        }

        scrollTargetY = clamp(scrollTargetY, minScrollY, maxScrollY);

        // updating our camera
        float t = 1.0f - exp(-smoothness * dt);
        camera.target.y += (scrollTargetY - camera.target.y) * t;
        camera.target.y = clamp(camera.target.y, minScrollY, maxScrollY);

        BeginDrawing();
            ClearBackground(BLACK);

            // while the cameras running...
            BeginMode2D(camera);
                for (const Card& card : cards) { // for every card
                    DrawCircleV({card.worldX, card.worldY}, card.radius, WHITE); // draw them where they should be

                    int circleTextFontSize = clamp(static_cast<int>(card.radius * 0.45f), 10, 24); // between 10 and 24 so its not abnormally small or large
                    int circleTextWidth = MeasureText(card.text.c_str(), circleTextFontSize);

                    int circleTextX = static_cast<int>(card.worldX) - (circleTextWidth/2);
                    int circleTextY = static_cast<int>(card.worldY) - (circleTextFontSize/2);

                    DrawText(card.text.c_str(), circleTextX, circleTextY, circleTextFontSize, BLACK);
                }
            EndMode2D();

            // writing the text for the milestones
            const float trackX = 115.0f;
            const int fontSize = 26;

            DrawLineEx({trackX, 0.0f}, {trackX, static_cast<float>(screenHeight)}, 1.0f, Fade(RAYWHITE, 0.15f));

            for (const Milestone& m : milestones) { // for every milestone within our milestones
                float screenY = m.worldY - camera.target.y;

                if (screenY >= -60.0f && screenY <= static_cast<float>(screenHeight) + 60.0f) {
                    string label = to_string(m.year);
                    int textWidth = MeasureText(label.c_str(), fontSize);

                    int textX = static_cast<int>(trackX) - textWidth - 24;
                    int textY = static_cast<int>(screenY) - (fontSize / 2);

                    DrawText(label.c_str(), textX, textY, fontSize, Fade(WHITE, 0.92f));
                }
            }

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);
                bool clickedAnyCard = false;

                // Check top-most drawn cards first if any overlap
                for (int i = static_cast<int>(cards.size()) - 1; i >= 0; --i) {
                    if (CheckCollisionPointCircle(mouseWorldPos, {cards[i].worldX, cards[i].worldY}, cards[i].radius)) {
                        if (activeCardIndex == i) {
                            activeCardIndex = -1; // Clicking the open card again closes it
                        } else {
                            activeCardIndex = i;  // Clicking a different card switches to it
                        }
                        clickedAnyCard = true;
                        break;
                    }
                }

                // clicking empty space should also close the box
                if (!clickedAnyCard) {
                    activeCardIndex = -1;
                }
            }

            for (const Card& card : cards) {
                if (activeCardIndex >= 0 && activeCardIndex < static_cast<int>(cards.size())) {
                    cards[activeCardIndex].DisplayDescription(screenWidth, screenHeight);
                }
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}