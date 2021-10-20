"""Useful things to do with dates"""
import datetime


def date_from_string(string, format_string=None):
    """Runs through a few common string formats for datetimes,
    and attempts to coerce them into a datetime. Alternatively,
    format_string can provide either a single string to attempt
    or an iterable of strings to attempt."""

    if isinstance(format_string, str):
        return datetime.datetime.strptime(string, format_string).date()

    elif format_string is None:
        format_string = [
            "%Y-%m-%d",
            "%m-%d-%Y",
            "%m/%d/%Y",
            "%d/%m/%Y",
        ]

    for format in format_string:
        try:
            return datetime.datetime.strptime(string, format).date()
        except ValueError:
            continue

    raise ValueError("Could not produce date from string: {}".format(string))


def to_datetime(plain_date, hours=0, minutes=0, seconds=0, ms=0):
    """given a datetime.date, gives back a datetime.datetime"""
    # don't mess with datetimes
    if isinstance(plain_date, datetime.datetime):
        return plain_date
    return datetime.datetime(
        plain_date.year,
        plain_date.month,
        plain_date.day,
        hours,
        minutes,
        seconds,
        ms,
    )


class TimePeriod(object):

    def __init__(self, earliest, latest):
        if not isinstance(earliest, datetime.date) and earliest is not None:
            raise TypeError("Earliest must be a date or None")
        if not isinstance(latest, datetime.date) and latest is not None:
            raise TypeError("Latest must be a date or None")

        # convert dates to datetimes, for to have better resolution
        if earliest is not None:
            earliest = to_datetime(earliest)
        if latest is not None:
            latest = to_datetime(latest, 23, 59, 59)

        if earliest is not None and latest is not None and earliest >= latest:
            raise ValueError("Earliest must be earlier than latest")

        self._earliest = earliest
        self._latest = latest

    def __contains__(self, key):
        if isinstance(key, datetime.date):
            key = to_datetime(key)

            if self._latest is None:
                upper_bounded = True
            else:
                upper_bounded = key <= self._latest

            if self._earliest is None:
                lower_bounded = True
            else:
                lower_bounded = self._earliest <= key

            return upper_bounded and lower_bounded

        elif isinstance(key, TimePeriod):
            if self._latest is None:
                upper_bounded = True
            elif key._latest is None:
                upper_bounded = False
            else:
                upper_bounded = self._latest >= key._latest

            if self._earliest is None:
                lower_bounded = True
            elif key._earliest is None:
                lower_bounded = False
            else:
                lower_bounded = self._earliest <= key._earliest

            return upper_bounded and lower_bounded

    def contains(self, other):
        return other in self

    def overlaps(self, other):
        """does another datetime overlap with this one? this is a symmetric
        property.

        TP1       |------------|
        -------------------------------------------------> time
        TP2                 |--------------|

        TP1.overlaps(TP2) == TP2.overlaps(TP1) == True

        args:
            other - a TimePeriod
        """

        return self._latest in other or self._earliest in other

    def __eq__(self, other):
        return (self._earliest == other._earliest) and (self._latest == other._latest)

    def __hash__(self):
        return hash((self._earliest, self._latest))

    def __repr__(self):
        return "<{}: {}-{}>".format(
            self.__class__.__name__,
            self._earliest,
            self._latest,
        )

    @classmethod
    def get_containing_period(cls, *periods):
        """Given a bunch of TimePeriods, return a TimePeriod that most closely
        contains them."""

        if any(not isinstance(period, TimePeriod) for period in periods):
            raise TypeError("periods must all be TimePeriods: {}".format(periods))

        latest = datetime.datetime.min
        earliest = datetime.datetime.max

        for period in periods:
            # the best we can do to conain None is None!
            if period._latest is None:
                latest = None
            elif latest is not None and period._latest > latest:
                latest = period._latest

            if period._earliest is None:
                earliest = None
            elif earliest is not None and period._earliest < earliest:
                earliest = period._earliest

        return TimePeriod(earliest, latest)


class DiscontinuousTimePeriod(object):
    """A bunch of TimePeriods"""

    def __init__(self, *periods):
        if any(not isinstance(period, TimePeriod) for period in periods):
            raise TypeError("periods must all be TimePeriods: {}".format(periods))

        periods = set(periods)

        no_overlaps_periods = []
        for period in periods:
            for other_period in periods:
                if id(other_period) == id(period):
                    continue

                # periods that overlap should be combined
                if period.overlaps(other_period):
                    period = TimePeriod.get_containing_period(period, other_period)

            no_overlaps_periods.append(period)

        no_equals_periods = []
        reference = set(no_overlaps_periods)
        for period in no_overlaps_periods:
            # clean out duplicated periods
            if any(other_period == period and other_period is not period for other_period in reference):
                reference.remove(period)
            else:
                no_equals_periods.append(period)

        no_contains_periods = []
        for period in no_equals_periods:
            # don't need to keep periods that are wholly contained
            skip = False
            for other_period in no_equals_periods:
                if id(other_period) == id(period):
                    continue

                if period in other_period:
                    skip = True

            if not skip:
                no_contains_periods.append(period)
        self._periods = no_contains_periods

    def __contains__(self, other):
        if isinstance(other, (datetime.date, TimePeriod)):
            for period in self._periods:
                if other in period:
                    return True


def days_ago(days, give_datetime=True):
    delta = datetime.timedelta(days=days)
    dt = datetime.datetime.now() - delta
    if give_datetime:
        return dt
    else:
        return dt.date()


def days_ahead(days, give_datetime=True):
    delta = datetime.timedelta(days=days)
    dt = datetime.datetime.now() + delta
    if give_datetime:
        return dt
    else:
        return dt.date()
