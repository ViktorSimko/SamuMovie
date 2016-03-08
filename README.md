# SamuMovie

This project is a fork of the https://github.com/nbatfai/SamuMovie repository, and it is used for an exercise of the High level programming languages course.

I've created a video converter, which transforms the given input video into 2D arrays of bool, and I've modified 
the [original](https://github.com/nbatfai/SamuMovie) Samu to be able to learn from this data.

[Example video](https://www.youtube.com/watch?v=GSpl4SDqw2M) 

[Samu](http://arxiv.org/abs/1511.02889) (Nahshon) has captured a movie. 
This is an example of the manuscript entitled "Samu in his prenatal development".

This project uses the same COP-based Q-learning engine as Samu ([Nahshon](https://github.com/nbatfai/nahshon)) 
to predict the next sentences of a conversation. 

After the basic work on the [joining](https://github.com/nbatfai/SamuLife) 
of Conway's Game of Life and Samu's COP engine is done, 
now I have started to work on creating a similar but much simpler example 
in which Samu must learn the frames of the moving picture.

## Usage

### v0.0.1

```
git clone https://github.com/nbatfai/SamuMovie.git
cd SamuMovie/
~/Qt/5.5/gcc_64/bin/qmake SamuLife.pro
make
./SamuMovie
```
[https://youtu.be/XOPORbI1hz4](https://youtu.be/XOPORbI1hz4)

![samumovie](https://cloud.githubusercontent.com/assets/3148120/12219039/13fe4f14-b732-11e5-9590-1bd0d875fc93.png)

### v0.0.2-predicting-the-present-eliminated

It is important to note that in the previous version the COP-based Q-learning 
has become trivial because after a short starting period it chooses the Q-action 
that was passed in as the actual cell state argument. It means that the agent 
does not predict the future but the present. This version has already been 
improved. It really predicts the future. It can be verify in [SamuLife](https://github.com/nbatfai/SamuLife)

[https://youtu.be/yOZj6j1kVRg](https://youtu.be/yOZj6j1kVRg)

## Other experiments

Samu (Nahshon)
http://arxiv.org/abs/1511.02889,
https://github.com/nbatfai/nahshon

---

SamuLife
https://github.com/nbatfai/SamuLife,
https://youtu.be/b60m__3I-UM

SamuMovie
https://github.com/nbatfai/SamuMovie,
https://youtu.be/XOPORbI1hz4

SamuStroop
https://github.com/nbatfai/SamuStroop,
https://youtu.be/6elIla_bIrw,
https://youtu.be/VujHHeYuzIk

SamuBrain
https://github.com/nbatfai/SamuBrain

SamuCopy
https://github.com/nbatfai/SamuCopy

---

SamuTicker
https://github.com/nbatfai/SamuTicker

SamuVocab
https://github.com/nbatfai/SamuVocab
