TEMPLATE = subdirs


CONFIG += ordered


SUBDIRS = RelaFix \
          RelaView

RelaView.depends = RelaFix

