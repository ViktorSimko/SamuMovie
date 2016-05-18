#include "Recorder.h"

void Recorder::record()
{
    std::cerr << "Recording to: " << fileName.toUtf8().constData() << std::endl;

    cv::VideoCapture cap(0); // open the video camera no. 0
    cv::VideoWriter oVideoWriter;//create videoWriter object, not initialized yet

    //cv::namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

    double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
    double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    std::cout << "Frame Size = " << dWidth << "x" << dHeight << std::endl;

    //set framesize for use with videoWriter
    cv::Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));
    int i = 0;
    oVideoWriter  = cv::VideoWriter(fileName.toUtf8().constData(), (int)cap.get(CV_CAP_PROP_FOURCC), 30, frameSize, true); //initialize the VideoWriter object

    while(i++ < 100) {

        cv::Mat frame;

        bool bSuccess = cap.read(frame); // read a new frame from video

        oVideoWriter.write(frame);
        std::cout << "frame " << i << std::endl;
        //cv::imshow("MyVideo", frame); //show the frame in "MyVideo" window
    }
}

Recorder::Recorder(const QString& fileNameToSave)
{
    this->fileName = fileNameToSave;
    recordButton = new QPushButton(tr("Record"));
    connect(recordButton, SIGNAL(clicked()), this, SLOT(record()));

    okButton = new QPushButton(tr("Ok!"));
    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));

    QGridLayout *main_layout = new QGridLayout;
    main_layout->addWidget(recordButton, 1, 0);
    main_layout->addWidget(okButton, 1, 1);
    setLayout(main_layout);

    setWindowTitle(tr("Samu Movie"));
    //resize(600, 300);
}

Recorder::~Recorder()
{
    delete okButton;
    delete recordButton;
}
