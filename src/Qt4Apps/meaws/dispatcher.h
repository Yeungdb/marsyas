#ifndef MEAWS_DISPATCHER_H
#define MEAWS_DISPATCHER_H

#include "defs.h"
#include "user.h"
#include "metro.h"
#include "backend.h"

#include "choose-exercise.h"

#include <QObject>

class Dispatcher : public QObject
{
	Q_OBJECT

public:
	Dispatcher(QFrame* centralFrame);
	~Dispatcher();

	QObject* getUserPointer()
	{
		return user_;
	};
	QObject* getExercisePointer()
	{
		return exercise_;
	};
	QObject* getMetroPointer()
	{
		return metro_;
	};

	bool close();

	QString getTitle();
	QString getStatus();

public slots:
	void openExercise();

	void openAttempt();
	void analyze();



	void toggleAttempt();
	void setAttempt(bool running);

	/*
		void open();
		void close();
		bool openAttempt();

		void playFile();

		void analysisDone(); // even tempier

		void newTry();

		void addTry()
		{
			exercise_->addTry();
		};
		void delTry()
		{
			exercise_->delTry();
		};

	*/
signals:
	void updateMain(int state);

private:
	// main object variables
	User *user_;
	Metro *metro_;
	Exercise *exercise_;
	MarBackend *marBackend_;

	// setup
	void setupExercise();

	// basic GUI frame
	QFrame *centralFrame_;

	// current exercise state
	bool attemptRunningBool_;
	/*
	//	void connectMain(QObject* mainWindow);

		// left-over garbage (?)
		QString exerciseName_;

		QString statusMessage_;
	*/
};
#endif

