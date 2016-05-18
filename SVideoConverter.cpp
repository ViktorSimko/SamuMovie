#include "SVideoConverter.h"

SVideoConverter::SVideoConverter(size_t w_w, size_t w_h) 
								: m_ww{w_w}, m_wh{w_h}
{
    //m_file_name = QFileDialog::getOpenFileName(this,
        //QObject::tr("Select Video"), "/home/viktor/", QObject::tr("Video Files (*.avi)"));
    m_file_name = tr("SamuVid.avi");
	m_cap.open(m_file_name.toUtf8().constData());

	// check if the stream is opened
	if ( !m_cap.isOpened() )
	{
		std::cerr << "Can't open video file!" << std::endl;
		throw std::exception();
	}

	// get the width and the height of the capture stream
	m_mw = m_cap.get(CV_CAP_PROP_FRAME_WIDTH);
	m_mh = m_cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    std::cerr << m_mw << ':' << m_mh << std::endl;

	// calculate the w and h of the cells in the movie
	m_cw = m_mw / m_ww;
	m_ch = m_mh / m_wh;
    std::cerr << m_cw << ':' << m_ch << std::endl;


	//Convert();
	
	b_convert = new QPushButton(tr("Convert"));

	connect(b_convert, SIGNAL(clicked()), this, SLOT(Convert()));

	b_launch_samu = new QPushButton(tr("Launch Samu"));

	connect(b_launch_samu, SIGNAL(clicked()), this, SLOT(accept()));

	QGridLayout *main_layout = new QGridLayout;
	main_layout->addWidget(b_convert, 1, 0);
	main_layout->addWidget(b_launch_samu, 1, 1);
	setLayout(main_layout);

	setWindowTitle(tr("Samu Movie"));
    //resize(600, 300);
	
}

void SVideoConverter::Convert()
{
	// create a Mat for the frames to read in
	cv::Mat tmp_frame;

	// temporary vector for storing bool data for Samu's lattices
	std::vector< std::vector< std::vector<bool> > > tmp_frames;

	size_t frame_num = 0;

	//cv::namedWindow("w1", 1);
	
	// we do things for all of the frames
	for (;;)
	{
		// get the next frame from the video stream
		m_cap >> tmp_frame;

		// if the current frame is empty then we arrived to the end of the stream
		if (tmp_frame.empty()) break;

		// if we've had a non-empty frame then reserve some storage for it
		tmp_frames.push_back(std::vector< std::vector<bool> > (m_wh, std::vector<bool>(m_ww)));

		// convert frame to grayscale
        std::cerr << tmp_frame.rows << ':' << tmp_frame.cols << std::endl;

		ConvertFrameToGS(tmp_frame);
        std::cerr << tmp_frame.rows << ':' << tmp_frame.cols << std::endl;
		
		// then loop through the pixels of the frame, with a gap of the size of one cell
        for (auto i = 0; i < tmp_frame.rows; i += m_ch)
		{
			//uchar *r = tmp_frame.ptr(i);
            for (auto j = 0; j < tmp_frame.cols; j += m_cw)
			{
				// create a Mat for masking the current ROI, filled with 0's
				cv::Mat cell_mask = cv::Mat::zeros(tmp_frame.rows, tmp_frame.cols, CV_8U);

				// define the current ROI by a Rect
                cv::Rect cell_mask_region = cv::Rect(j, i, m_cw, m_ch);

				// fill the ROI with 1's in the mask
				cell_mask(cell_mask_region) = 1;

				//std::cout << (cv::mean(tmp_frame, cell_mask))[0] << std::endl;
				
				// calculate the mean of the ROI
				if ((cv::mean(tmp_frame, cell_mask))[0] > 127)
				{
					// tmp_frame(cell_mask_region) = 255;

					// if the value is high enough we can set it to white
					tmp_frames[frame_num][i / m_ch][j / m_cw] = false;
				}
				else
				{
					//tmp_frame(cell_mask_region) = 0;

					// else we can set it to black
					tmp_frames[frame_num][i / m_ch][j / m_cw] = true;
				}
				
			}
		}

		// give some feedback for the user
		std::cout << "Converting frame:\t[" << std::setfill('0') 
				  << std::setw(3) << frame_num << "]" << std::endl;


		frame_num++;
		
		//std::cerr << tmp_frame.type() << std::endl;

		//cv::imshow("w1", tmp_frame);
		//if (cv::waitKey(25) == 27) break;
	}

	// move the temporary vector to the member variable
	m_lattices = std::move(tmp_frames);
}

// Ironically this method is for converting one frame to grayscale...
void SVideoConverter::ConvertFrameToGS(cv::Mat& frame)
{
	cv::Mat grey_mat;

	cv::cvtColor(frame, grey_mat, CV_BGR2GRAY);

	frame = grey_mat;
}
