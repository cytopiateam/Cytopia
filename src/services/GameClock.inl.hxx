template <typename DelayType, typename PeriodType>
GameClock::ClockTaskHndl GameClock::addRealTimeClockTask(ClockCbk cbk, DelayType delay, PeriodType period)
{
  if ((cbk != nullptr) && (TimePoint(delay) > TimePointZero) && (TimePoint(period) >= TimePointZero))
  {
    std::lock_guard<std::mutex> lock(m_lock);
    m_realTimeTasks.add(RealTimeClockTask(cbk, TimePoint(Clock::now() + (TimePoint(delay) - TimePointZero)), TimePoint(period),
                                          ++m_unique_handle));
    return m_unique_handle;
  }
  else
  {
    return ClockTaskHndlInvalid;
  }
}
