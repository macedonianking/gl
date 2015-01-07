#ifndef GL_WC_ANIMATOR_H_
#define GL_WC_ANIMATOR_H_

#include "wc_time.h"

class WcAnimator;
class WcAnimatorTarget;
class WcAnimatorManager;

class AnimatorListener
{
public:
	AnimatorListener();

	virtual ~AnimatorListener();

	virtual void OnAnimatorStart(WcAnimator *animator);
	virtual void OnAnimatorUpdate(WcAnimator *animator, float t);
	virtual void OnAnimatorRepeat(WcAnimator *animator, int n);
	virtual void OnAnimatorEnd(WcAnimator *animator);
	virtual void OnAnimatorCancel(WcAnimator *animator);
};

class WcAnimator 
{
public:
	WcAnimator();
	virtual ~WcAnimator();

	enum Status
	{
		kStatusDefault = 0,
		kStatusPrepare = 1,
		kStatusRunning = 2,
		kStatusStopped = 3,
	};

	enum
	{
		MAX_TIMES_NONE = 0,
		MAX_TIMES_INFINITE = -1,
	};

	void Start();
	void Cancel();

	void SetMaxTimes(int maxTimes);
	void SetDuration(millis_t duration);
	void Update();

	bool IsRunning() const {
		return mStatus == kStatusRunning || mStatus == kStatusPrepare;
	}

protected:
	virtual void OnUpdateFromTime(float t);

private:
	Status 			mStatus;
	int 			mRepeatTimes;
	int				mMaxRepeatTimes;
	millis_t		mStartMillis;
	millis_t		mDuration;

	AnimatorListener	*mAnimatorListener;
};

#endif // GL_WC_ANIMATOR_H_
