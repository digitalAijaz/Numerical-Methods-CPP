#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <ios>
#include <fstream>

using namespace std;

class RandomNumberGenerator
{
public:
    RandomNumberGenerator()
    {
        std::cout << fixed << setprecision(2);
        rng.seed(rd());
    }

    template <typename Distribution>
    double generateRandomNumber(Distribution dist)
    {
        return dist(rng);
    }

private:
    std::random_device rd;
    std::mt19937 rng;
};

void probabilitySelection1()
{
    float targetPosition = 25.5;
    vector<float> segmentLengths{ 5.2f, 12.3f, 8.5f, 15.6f };
    vector<string> segments{ "Hand", "Arm", "Forearm", "Trunk" };

    RandomNumberGenerator rng;

    int k = 0;
    float totalLength = segmentLengths[k];

    int iteration{ 0 };
    std::cout << "Iteration " << iteration << " : ";
    std::cout << "Segment " << segments[k] << " is selected\n";

    while ((targetPosition - totalLength) > 0)
    {
        double targetDisRemain = (targetPosition - totalLength) / targetPosition;

        // Generate a random number using the uniform distribution
        std::uniform_real_distribution<double> uniformDist(targetDisRemain / 2, 1.5 * targetDisRemain);
        double randomNumber = rng.generateRandomNumber(uniformDist);

        if (randomNumber >= targetDisRemain)
        {
            std::cout << "Iteration " << ++iteration << " : ";
            std::cout << "Segment " << segments[++k] << " is selected (Distance Remaining = " << targetDisRemain << " randomNumber = " << randomNumber << " )\n";
            totalLength += segmentLengths[k];
        }

        else
        {
            std::cout << "Iteration " << ++iteration << " : ";
            std::cout << "No Additional Segment is selected (Distance Remaining = " << targetDisRemain << " randomNumber = " << randomNumber << " )\n";
        }
    }
}

void probabilitySelection2()
{
    float targetPosition = 28.0;
    vector<float> segmentLengths{ 5.2f, 12.3f, 8.5f, 25.6f };
    vector<string> segments{ "Hand", "Arm", "Forearm", "Trunk" };

    RandomNumberGenerator rng;

    //  int iteration{0};
    //  cout << "Iteration " << iteration << " : ";
    //  cout << "Segment " << segments[k] << " is selected\n";

    float threeSegLength{ 0 };
    float fourSegLength{ 0 };

    for (auto i = 0; i < segmentLengths.size(); i++)
        fourSegLength += segmentLengths[i];

    threeSegLength = fourSegLength - segmentLengths[3];

    ofstream file;
    // Open a file stream for writing
    file.open("data.csv");

    file << "Target position: "
        << "," << targetPosition << endl;
    file << "3 Segment length: "
        << "," << threeSegLength << endl;
    file << "4 Segment length: "
        << "," << fourSegLength << endl;

    file << ","
        << ","
        << "numIter, fourSegCount, threeSegCount,fourSegProb, threeSegProb\n";

    int numIter{ 1 };

    for (size_t j = 0; j <= 8; j++)
    {
        numIter = pow(10, j);

        int fourSegCount = 0;
        int threeSegCount = 0;
        int twoSegCount = 0;

        for (int i = 0; i < numIter; i++)
        {
            int k = 0;
            double randomNumberSegLength;
            // Generate a random number using the uniform distribution for perceiving the segment length                    std::uniform_real_distribution<double> uniformDist(0.9, 1.1);
            std::uniform_real_distribution<double> uniformDist(0.9, 1.1);
            randomNumberSegLength = rng.generateRandomNumber(uniformDist);

            float totalLength = segmentLengths[k] * randomNumberSegLength;

            // Generate a random number using the uniform distribution for perceiving the target distance
           // std::uniform_real_distribution<double> uniformDist(0.9, 1.1);
            double randomNumberTarget = rng.generateRandomNumber(uniformDist);
            // cout << randomNumberTarget << endl;

            float percievedTargetPosition = targetPosition * randomNumberTarget;

            while ((percievedTargetPosition - totalLength) > 0)
            {
                double targetDisRemain = (percievedTargetPosition - totalLength) / percievedTargetPosition;

                // Generate a random number using the uniform distribution
              //  std::uniform_real_distribution<double> uniformDist(targetDisRemain / 2, 1.5 * targetDisRemain);
                double randomNumber = rng.generateRandomNumber(uniformDist);

                if (randomNumber >= targetDisRemain)
                {
                    //  cout << "Iteration " << ++iteration << " : ";
                    //  cout << "Segment " << segments[++k] << " is selected (Distance Remaining = " << targetDisRemain << " randomNumber = " << randomNumber << " )\n";
                    k++;
                    // Generate a random number using the uniform distribution for perceiving the segment length                    std::uniform_real_distribution<double> uniformDist(0.9, 1.1);
                 //   std::uniform_real_distribution<double> uniformDist(0.9, 1.1);
                    randomNumberSegLength = rng.generateRandomNumber(uniformDist);
                    totalLength += segmentLengths[k] * randomNumberSegLength;
                }

                else
                {
                    //  cout << "Iteration " << ++iteration << " : ";
                    //  cout << "No Additional Segment is selected (Distance Remaining = " << targetDisRemain << " randomNumber = " << randomNumber << " )\n";
                    continue;
                }
            }
            if (k == 3)
                fourSegCount++;

            else if (k == 2)
                threeSegCount++;

            else if (k == 1)
                twoSegCount++;
        }
        /*
                std::cout << "Number of times Four Segments Involved: " << fourSegCount << endl;
                std::cout << "Number of times Three Segments Involved: " << threeSegCount << endl;
                // std::cout<<"Number of times Two Segments Involved: "<<twoSegCount<<endl;

                std::cout << "Probability that all four segments are selected: " << (float)(fourSegCount) / numIter << endl;
                std::cout << "Probability that three segments are selected: " << (float)(threeSegCount) / numIter << endl;
                // std::cout << "Probability that two segments are selected: " << (float)(twoSegCount) / numIter << endl;
        */
        file << ","
            << "," << numIter << "," << fourSegCount << "," << threeSegCount << "," << (float)(fourSegCount) / numIter << "," << (float)(threeSegCount) / numIter << endl;
    }
    // Close the file stream
    file.close();
}

void probabilitySelection3()                   //Using Unifrom Random Number
{
    float targetPosition = 1.0;//28.0;
    vector<float> segmentLengths{ 5.2f, 12.3f, 8.5f, 25.6f };
    vector<string> segments{ "Hand", "Arm", "Forearm", "Trunk" };

    RandomNumberGenerator rng;

    //  int iteration{0};
    //  cout << "Iteration " << iteration << " : ";
    //  cout << "Segment " << segments[k] << " is selected\n";

    float threeSegLength{ 0 };
    float fourSegLength{ 0 };

    for (auto i = 0; i < segmentLengths.size(); i++)
        fourSegLength += segmentLengths[i];

    threeSegLength = fourSegLength - segmentLengths[3];

    ofstream file;
    // Open a file stream for writing
    file.open("data.csv");

    

    int numIter{ 1 };

    //target Positions
    vector<float> targetPositions{ 21.0,22.0,23.0,24.0,25.0,26.0,27.0,28.0,29.0,30.0 };

    for (auto q = 0; q < targetPositions.size(); q++)
    {
        targetPosition = targetPositions[q];

        file << "Target position: "
            << "," << targetPosition << endl;
        file << "3 Segment length: "
            << "," << threeSegLength << endl;
        file << "4 Segment length: "
            << "," << fourSegLength << endl;

        file << ","
            << ","
            << "numIter, fourSegCount, threeSegCount,fourSegProb, threeSegProb\n";
        //Loop for number of times the the task is performed
        for (size_t j = 0; j <= 8; j++)
        {
            numIter = pow(10, j);

            int fourSegCount = 0;
            int threeSegCount = 0;
            int twoSegCount = 0;

            for (int i = 0; i < numIter; i++)
            {
                int k = 0;
                double randomNumberSegLength;
                //Generate a random number using the uniform distribution for perceiving the initial segment length
                //It can be under or overestimated  
                std::uniform_real_distribution<double> uniformDist(0.9, 1.1);
                randomNumberSegLength = rng.generateRandomNumber(uniformDist);

                float totalLength = segmentLengths[k] * randomNumberSegLength;

                //Generate a random number using the uniform distribution for perceiving the target distance. t1 & t2 are used 
                //t1 for underestimation
                //t2 for overestimation
                float t1 = 0.9f;
                float t2 = 1.1f;
                std::uniform_real_distribution<double> uniformDistTarget(t1, t2);
                double randomNumberTarget = rng.generateRandomNumber(uniformDistTarget);
                // cout << randomNumberTarget << endl;

                float percievedTargetPosition = targetPosition * randomNumberTarget;

                float d = percievedTargetPosition - totalLength;

                while (d > 0 && k < segmentLengths.size())
                {
                    double targetDisRemain = (percievedTargetPosition - totalLength) / percievedTargetPosition;

                    // Generate a random number using the uniform distribution
                    std::uniform_real_distribution<double> uniformDist1(targetDisRemain / 2, 1.5 * targetDisRemain);
                    double randomNumber = rng.generateRandomNumber(uniformDist1);

                    //Toss of coin. Not of much importance in this study.
                    if (randomNumber >= targetDisRemain)
                    {
                       // cout << "Segment " << segments[++k] << " is selected (Distance Remaining = " << targetDisRemain << " randomNumber = " << randomNumber << " )\n";
                        k++;
                        if (k >= segmentLengths.size()) {
                            // Handle the case where k exceeds the size of the vector
                            break;
                        }
                        // Generate a random number using the uniform distribution for perceiving the segment length                    std::uniform_real_distribution<double> uniformDist(0.9, 1.1);
                        // std::uniform_real_distribution<double> uniformDist(0.9, 1.1);
                        randomNumberSegLength = rng.generateRandomNumber(uniformDist);
                        totalLength += segmentLengths[k] * randomNumberSegLength;

                        //As the target distance becomes less, error in perception of distance (over and under-estimation) also reduces
                        //This is ensured using two parameters t1 & t2.
                        //Both undere-stimation and over-estimation reduce as the target distance reduces
                        t1 = 0.9 + k * 0.015;
                        t2 = 1.1 - k * 0.015;
                        std::uniform_real_distribution<double> uniformDistUpdatedTarget(t1, t2);
                        randomNumberTarget = rng.generateRandomNumber(uniformDistUpdatedTarget);
                        d = (percievedTargetPosition - totalLength) * randomNumberTarget;
                    }

                    else
                    {
                        //  cout << "Iteration " << ++iteration << " : ";
                        //  cout << "No Additional Segment is selected (Distance Remaining = " << targetDisRemain << " randomNumber = " << randomNumber << " )\n";
                        continue;
                    }

                }
                if (k == 3)
                    fourSegCount++;

                else if (k == 2)
                    threeSegCount++;

                else if (k == 1)
                    twoSegCount++;
            }
            
            file << ","
                << "," << numIter << "," << fourSegCount << "," << threeSegCount << "," << (float)(fourSegCount) / numIter << "," << (float)(threeSegCount) / numIter << endl;
        }
        file << endl<<endl;
    }
    
    // Close the file stream
    file.close();
}




void probabilitySelection4()                                          //Using Normal Distribution
//SD needs to be improved
{
    float targetPosition = 1.0;//28.0;
    vector<float> segmentLengths{ 5.2f, 12.3f, 8.5f, 25.6f };
    vector<string> segments{ "Hand", "Arm", "Forearm", "Trunk" };

    RandomNumberGenerator rng;

    //  int iteration{0};
    //  cout << "Iteration " << iteration << " : ";
    //  cout << "Segment " << segments[k] << " is selected\n";

    float twoSegLength{ 0 };
    float threeSegLength{ 0 };
    float fourSegLength{ 0 };

    for (auto i = 0; i < segmentLengths.size(); i++)
        fourSegLength += segmentLengths[i];

    threeSegLength = fourSegLength - segmentLengths[3];
    twoSegLength = threeSegLength - segmentLengths[2];

    ofstream file;
    // Open a file stream for writing
    file.open("data.csv");



    int numIter{ 1 };

    //target Positions
    vector<float> targetPositions{ 21.0,22.0,23.0,24.0,25.0,26.0,27.0,28.0,29.0,30.0 };

    for (auto q = 0; q < targetPositions.size(); q++)
    {
        targetPosition = targetPositions[q];

        file << "Target position: "
            << "," << targetPosition << endl;
        file << "2 Segment length: "
            << "," << twoSegLength << endl;
        file << "3 Segment length: "
            << "," << threeSegLength << endl;
        file << "4 Segment length: "
            << "," << fourSegLength << endl;

        file << ","
            << ","
            << "numIter, fourSegCount, threeSegCount, twoSegCount, fourSegProb, threeSegProb, twoSegProb\n";
        //Loop for number of times the the task is performed
        for (size_t j = 0; j <= 3; j++)
        {
            numIter = pow(10, j);

            int fourSegCount = 0;
            int threeSegCount = 0;
            int twoSegCount = 0;

            for (int i = 0; i < numIter; i++)
            {
                int k = 0;
                double randomNumberSegLength;
                //Generate a random number using the uniform distribution for perceiving the initial segment length
                //It can be under or overestimated
                std::normal_distribution<double> normalDist(segmentLengths[0], segmentLengths[0] / 15);
                randomNumberSegLength = rng.generateRandomNumber(normalDist);

                float totalLength = segmentLengths[k] * randomNumberSegLength;

                //Generate a random number using the normal distribution for perceiving the target distance. t1 & t2 are used
                float SD = targetPosition / 10;
                std::normal_distribution<double> normalDistTarget(targetPosition, SD);
                double randomNumberTarget = rng.generateRandomNumber(normalDistTarget);
                float percievedTargetPosition = targetPosition * randomNumberTarget;

                float d = percievedTargetPosition - totalLength;

                while (d > 0 && k < segmentLengths.size())
                {
                        k++;
                        if (k >= segmentLengths.size()) {
                            // Handle the case where k exceeds the size of the vector
                            break;
                        }
                        // Generate a random number using the normal distribution for perceiving the segment length                    std::uniform_real_distribution<double> uniformDist(0.9, 1.1);
                        std::normal_distribution<double> normalDist(segmentLengths[k], segmentLengths[k] / 15);
                        randomNumberSegLength = rng.generateRandomNumber(normalDist);

                        totalLength += segmentLengths[k] * randomNumberSegLength;

                        //As the target distance becomes less, error in perception of distance (over and under-estimation) also reduces
                        //This is ensured by reducing SD
                        //d = (percievedTargetPosition - totalLength);
                        SD = d/(10);
                        std::normal_distribution<double> normalUpdatedTarget(d, SD);
                        randomNumberTarget = rng.generateRandomNumber(normalUpdatedTarget);
                        d = (percievedTargetPosition - totalLength) * randomNumberTarget;

                }
                if (k == 3)
                    fourSegCount++;

                else if (k == 2)
                    threeSegCount++;

                else if (k == 1)
                    twoSegCount++;
            }
            file << ","
                << "," << numIter << "," << fourSegCount << "," << threeSegCount << "," << twoSegCount << "," << (float)(fourSegCount) / numIter << "," << (float)(threeSegCount) / numIter << "," << (float)(twoSegCount) / numIter << endl;
        }
        file << endl << endl;
    }

    // Close the file stream
    file.close();
}


int main()
{
    //probabilitySelection1();
    //probabilitySelection2();
    //probabilitySelection3();
    probabilitySelection4();

    return 0;
}



