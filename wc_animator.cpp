#include "wc_animator.h"

#include "base_config.h"
#include "wc_context.h"

#define WC_ANIMATOR_STATE_UPDATE		0x0000
#define WC_ANIMATOR_STATE_REPEAT		0x0001
#define WC_ANIMATOR_STATE_FINISH		0x0002

#define WC_DEFAULT_DURATION	((millis_t)300)

AnimatorListener::AnimatorListener()
{
}

AnimatorListener::~AnimatorListener()
{
}

void AnimatorListener::OnAnimatorStart(WcAnimator *animator)
{
}

void AnimatorListener::OnAnimatorUpdate(WcAnimator *animator, float t)
{
}

void AnimatorListener::OnAnimatorRepeat(WcAnimator *animator, int n)
{
}

void AnimatorListener::OnAnimatorEnd(WcAnimator *animator)
{
}

void AnimatorListener::OnAnimatorCancel(WcAnimator *animator)
{
}

WcAnimator::WcAnimator() :
	mStatus(kStatusDefault),
	mRepeatTimes(0),
	mMaxRepeatTimes(MAX_TIMES_NONE),
	mStartMillis(WcTime::kTimeMillisNull),
	mDuration(WC_DEFAULT_DURATION),
	mAnimatorListener(NULL)
{
}

WcAnimator::~WcAnimator()
{
}

void WcAnimator::Start()
{
	if(mStatus == kStatusDefault || mStatus == kStatusStopped) {
		mStatus = kStatusPrepare;
		this->mRepeatTimes = 0;
		this->mStartMillis = WcTime::CurrentTimeMillis();
	}
}

void WcAnimator::Cancel()
{
	if (mStatus == kStatusRunning) {
		mStatus = kStatusStopped;
		if (mAnimatorListener != NULL) {
			mAnimatorListener->OnAnimatorCancel(this);
		}
	} else if (mStatus != kStatusDefault) {
		mStatus = kStatusStopped;
	}
}

void WcAnimator::SetMaxTimes(int maxTimes)
{
	if (maxTimes <= MAX_TIMES_INFINITE) {
		maxTimes = MAX_TIMES_INFINITE;
	}
}

void WcAnimator::SetDuration(millis_t duration) {
	DCHECK(duration > 0) << "duration must be positive, but argument is :" << duration;
	this->mDuration = duration;
}

void WcAnimator::Update() {
	millis_t now = WcTime::CurrentTimeMillis();
	millis_t delta = now - mStartMillis;
	bool repeatHappened = false;
	float t;

	if (delta < 0) {
		delta = 0;
	}

	if (mStatus == kStatusPrepare) {
		mStatus = kStatusRunning;
		if (mAnimatorListener != NULL) {
			mAnimatorListener->OnAnimatorStart(this);
		}
	}

	if (delta > mDuration) {
		delta = mDuration;
		++mRepeatTimes;
		if (mMaxRepeatTimes == MAX_TIMES_INFINITE) {
			repeatHappened = true;
		} else if(mMaxRepeatTimes == MAX_TIMES_NONE) {
			mStatus = kStatusStopped;
		} else if (mRepeatTimes >= mMaxRepeatTimes) {
			mStatus = kStatusStopped;
		}
	} 

	t = delta * 1.0F / mDuration;
	this->OnUpdateFromTime(t);

	if (repeatHappened) {
		if(mAnimatorListener != NULL) {
			mAnimatorListener->OnAnimatorRepeat(this, this->mRepeatTimes);
		}
	} else if (mStatus == kStatusStopped) {
		mRepeatTimes = 0;
		if (mAnimatorListener != NULL) {
			mAnimatorListener->OnAnimatorEnd(this);
		}
	}
}

void WcAnimator::OnUpdateFromTime(float t)
{
}