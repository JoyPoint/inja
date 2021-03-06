// Copyright (c) 2019 Pantor. All rights reserved.

#include "hayai/hayai.hpp"
#include <inja/inja.hpp>

using json = nlohmann::json;

inja::Environment env;

json smallData = {
    {"name", "Peter"},
    {"list001", {"lorem", "ipsum", "dolor", "sit", "amet", "consectetur", "adipiscing", "elit", "aliquam", "accumsan"}},
    {"list002", {"donec", "in", "egestas", "diam", "aenean", "suscipit", "scelerisque", "efficitur", "integer", "a"}},
    {"list003", {"maecenas", "metus", "erat", "vestibulum", "quis", "porta", "in", "consequat", "sed", "justo"}},
};

json largeData = {
    {"name", "Peter"},
    {"list001", {"lorem", "ipsum", "dolor", "sit", "amet", "consectetur", "adipiscing", "elit", "aliquam", "accumsan"}},
    {"list002", {"donec", "in", "egestas", "diam", "aenean", "suscipit", "scelerisque", "efficitur", "integer", "a"}},
    {"list003", {"maecenas", "metus", "erat", "vestibulum", "quis", "porta", "in", "consequat", "sed", "justo"}},
    {"list004", {"aliquam", "erat", "volutpat", "integer", "laoreet", "tellus", "ut", "nibh", "viverra", "in"}},
    {"list005", {"integer", "eu", "velit", "ac", "erat", "fringilla", "ullamcorper", "id", "in", "tortor"}},
    {"list006", {"quisque", "at", "dapibus", "ante", "donec", "et", "lectus", "sit", "amet", "lorem"}},
    {"list007",
     {"curabitur", "imperdiet", "nibh", "sit", "amet", "pellentesque", "tincidunt", "quisque", "ornare", "enim"}},
    {"list008",
     {"aliquam", "vitae", "condimentum", "libero", "non", "sodales", "metus", "vestibulum", "aliquet", "ullamcorper"}},
    {"list009", {"pellentesque", "sed", "diam", "tellus", "donec", "sed", "nulla", "lorem", "sed", "imperdiet"}},
    {"list010", {"nam", "sagittis", "maximus", "congue", "class", "aptent", "taciti", "sociosqu", "ad", "litora"}},
    {"list011",
     {"praesent", "semper", "elit", "ut", "consequat", "fringilla", "mauris", "turpis", "volutpat", "risus"}},
    {"list012", {"nullam", "risus", "urna", "facilisis", "sit", "amet", "nibh", "id", "blandit", "mollis"}},
    {"list013", {"donec", "non", "ante", "nisi", "praesent", "suscipit", "erat", "quis", "lorem", "convallis"}},
    {"list014",
     {"maecenas", "tincidunt", "suscipit", "ipsum", "non", "tristique", "proin", "accumsan", "cursus", "justo"}},
    {"list015", {"nulla", "facilisi", "nullam", "et", "enim", "finibus", "aliquet", "mi", "ut", "mattis"}},
    {"list016", {"fusce", "rutrum", "lobortis", "ligula", "vitae", "condimentum", "risus", "ultrices", "sed", "sed"}},
    {"list017", {"nullam", "quis", "tristique", "ante", "proin", "neque", "ante", "sollicitudin", "non", "bibendum"}},
    {"list018", {"nam", "bibendum", "quam", "et", "semper", "eleifend", "donec", "placerat", "scelerisque", "mi"}},
    {"list019", {"donec", "vel", "suscipit", "turpis", "cras", "semper", "arcu", "in", "velit", "hendrerit"}},
    {"list020",
     {"praesent", "congue", "gravida", "mauris", "integer", "ornare", "dictum", "lorem", "non", "consequat"}},
    {"list021", {"nam", "tincidunt", "tortor", "sit", "amet", "gravida", "dapibus", "fusce", "laoreet", "nulla"}},
    {"list022", {"in", "id", "enim", "pellentesque", "suscipit", "velit", "id", "posuere", "metus", "quisque"}},
    {"list023", {"curabitur", "elit", "ex", "aliquam", "eget", "mi", "sed", "tristique", "scelerisque", "ligula"}},
    {"list024", {"vivamus", "dui", "lacus", "hendrerit", "eu", "sagittis", "non", "finibus", "consequat", "turpis"}},
    {"list025", {"etiam", "ultrices", "vel", "massa", "non", "vehicula", "duis", "aliquet", "massa", "id"}},
    {"list026", {"duis", "ultrices", "sem", "a", "sapien", "dignissim", "hendrerit", "eu", "vel", "sem"}},
    {"list027", {"vivamus", "eu", "elit", "ac", "metus", "pharetra", "pretium", "etiam", "mattis", "velit"}},
    {"list028", {"ut", "ac", "commodo", "risus", "nam", "eget", "hendrerit", "magna", "vestibulum", "elementum"}},
    {"list029", {"mauris", "in", "ultricies", "tellus", "ut", "in", "velit", "porttitor", "vulputate", "enim"}},
    {"list030", {"donec", "dapibus", "urna", "ac", "scelerisque", "mollis", "urna", "orci", "congue", "nulla"}},
    {"list031", {"vivamus", "eleifend", "dapibus", "maximus", "donec", "eu", "accumsan", "nulla", "eu", "iaculis"}},
    {"list032", {"aliquam", "erat", "volutpat", "orci", "varius", "natoque", "penatibus", "et", "magnis", "dis"}},
    {"list033", {"maecenas", "laoreet", "sed", "quam", "eget", "bibendum", "etiam", "et", "sollicitudin", "mi"}},
    {"list034", {"aliquam", "rhoncus", "purus", "vel", "nibh", "laoreet", "pharetra", "vestibulum", "ante", "ipsum"}},
    {"list035", {"quisque", "semper", "urna", "vel", "mollis", "gravida", "fusce", "nibh", "mauris", "porttitor"}},
    {"list036", {"sed", "luctus", "risus", "et", "sodales", "mollis", "maecenas", "a", "tincidunt", "risus"}},
    {"list037", {"in", "hac", "habitasse", "platea", "dictumst", "nullam", "fermentum", "commodo", "tempor", "aenean"}},
    {"list038", {"nunc", "rhoncus", "diam", "magna", "ac", "lacinia", "felis", "consequat", "non", "maecenas"}},
    {"list039", {"sed", "scelerisque", "velit", "est", "sed", "mollis", "ligula", "cursus", "sed", "aliquam"}},
    {"list040", {"nulla", "dictum", "arcu", "eu", "mauris", "malesuada", "quis", "cursus", "nisi", "faucibus"}},
    {"list041",
     {"phasellus", "posuere", "lacus", "nec", "molestie", "accumsan", "metus", "tortor", "facilisis", "nunc"}},
    {"list042", {"curabitur", "ex", "neque", "pretium", "sit", "amet", "leo", "in", "tempus", "vestibulum"}},
    {"list043", {"curabitur", "tortor", "tortor", "fermentum", "eget", "velit", "ac", "cursus", "faucibus", "odio"}},
    {"list044", {"aenean", "varius", "malesuada", "sapien", "sed", "hendrerit", "purus", "molestie", "sed", "sed"}},
    {"list045", {"nam", "hendrerit", "pretium", "purus", "id", "fermentum", "nunc", "in", "lacus", "metus"}},
    {"list046", {"fusce", "euismod", "libero", "sed", "diam", "pharetra", "non", "semper", "elit", "accumsan"}},
    {"list047", {"phasellus", "sed", "ligula", "sit", "amet", "justo", "vestibulum", "fermentum", "congue", "sed"}},
    {"list048", {"sed", "dignissim", "felis", "eget", "elit", "dictum", "malesuada", "vivamus", "maximus", "mi"}},
    {"list049", {"proin", "lobortis", "tempus", "molestie", "sed", "tortor", "ipsum", "finibus", "non", "aliquet"}},
    {"list050", {"integer", "ut", "leo", "dui", "proin", "condimentum", "dolor", "a", "suscipit", "maximus"}},
    {"list051", {"vivamus", "sapien", "neque", "dapibus", "sed", "volutpat", "at", "vestibulum", "sit", "amet"}},
    {"list052", {"curabitur", "enim", "enim", "faucibus", "sit", "amet", "luctus", "aliquam", "placerat", "nec"}},
    {"list053", {"suspendisse", "ligula", "dolor", "ultricies", "sit", "amet", "iaculis", "vel", "luctus", "sit"}},
    {"list054", {"aenean", "aliquam", "elit", "sit", "amet", "ultricies", "lobortis", "nullam", "porttitor", "libero"}},
    {"list055",
     {"ut", "tincidunt", "convallis", "placerat", "suspendisse", "potenti", "cras", "commodo", "fringilla", "lacus"}},
    {"list056", {"nulla", "quis", "elit", "est", "etiam", "sagittis", "molestie", "porta", "lorem", "ipsum"}},
    {"list057", {"in", "turpis", "nibh", "gravida", "vitae", "ex", "eu", "eleifend", "tincidunt", "neque"}},
    {"list058", {"suspendisse", "in", "fermentum", "orci", "etiam", "viverra", "metus", "a", "condimentum", "blandit"}},
    {"list059", {"fusce", "dapibus", "velit", "id", "est", "maximus", "rhoncus", "quisque", "lobortis", "tortor"}},
    {"list060", {"ut", "molestie", "ornare", "velit", "id", "consectetur", "nunc", "varius", "eu", "vivamus"}},
    {"list061", {"aenean", "egestas", "nibh", "at", "tincidunt", "varius", "felis", "metus", "ullamcorper", "purus"}},
    {"list062", {"donec", "a", "eleifend", "libero", "sed", "fermentum", "sem", "fusce", "eget", "lacinia"}},
    {"list063", {"nullam", "metus", "mauris", "ornare", "in", "sem", "at", "posuere", "placerat", "nisl"}},
    {"list064", {"maecenas", "vitae", "enim", "ipsum", "sed", "mattis", "porta", "mi", "congue", "suscipit"}},
    {"list065", {"nulla", "placerat", "porttitor", "metus", "non", "suscipit", "turpis", "rhoncus", "non", "etiam"}},
    {"list066", {"morbi", "id", "fringilla", "quam", "eget", "sollicitudin", "felis", "aliquam", "quis", "risus"}},
    {"list067",
     {"pellentesque", "maximus", "leo", "ut", "quam", "consequat", "lacinia", "suspendisse", "facilisis", "leo"}},
    {"list068", {"phasellus", "rhoncus", "urna", "felis", "nullam", "pharetra", "porttitor", "neque", "sit", "amet"}},
    {"list069", {"in", "posuere", "mauris", "sit", "amet", "nisl", "tempor", "eget", "euismod", "neque"}},
    {"list070",
     {"mauris", "id", "lobortis", "magna", "suspendisse", "nisl", "orci", "auctor", "suscipit", "malesuada"}},
    {"list071", {"ut", "facilisis", "magna", "vitae", "ligula", "laoreet", "tempor", "class", "aptent", "taciti"}},
    {"list072", {"aenean", "sagittis", "lacus", "vel", "nulla", "porta", "quis", "egestas", "sem", "ullamcorper"}},
    {"list073", {"donec", "eget", "purus", "scelerisque", "rutrum", "dolor", "eget", "maximus", "dui", "aliquam"}},
    {"list074", {"donec", "congue", "a", "massa", "vel", "posuere", "donec", "ullamcorper", "elit", "id"}},
    {"list075", {"praesent", "consectetur", "est", "eu", "tellus", "dictum", "tempor", "nullam", "id", "risus"}},
    {"list076", {"etiam", "gravida", "gravida", "tempus", "fusce", "lobortis", "orci", "ac", "volutpat", "mollis"}},
    {"list077", {"quisque", "quis", "turpis", "et", "augue", "dignissim", "maximus", "donec", "vel", "justo"}},
    {"list078", {"aenean", "consectetur", "mi", "non", "nibh", "bibendum", "ac", "tincidunt", "dui", "tristique"}},
    {"list079", {"aliquam", "tempus", "elit", "non", "ipsum", "finibus", "ut", "luctus", "dolor", "tincidunt"}},
    {"list080", {"donec", "eget", "ultricies", "tellus", "et", "imperdiet", "tellus", "vivamus", "maximus", "massa"}},
    {"list081",
     {"pellentesque", "eget", "volutpat", "velit", "eu", "venenatis", "mi", "suspendisse", "fringilla", "dignissim"}},
    {"list082", {"maecenas", "auctor", "leo", "sed", "sapien", "vehicula", "nec", "porttitor", "ante", "porta"}},
    {"list083", {"nulla", "risus", "lectus", "interdum", "rutrum", "aliquam", "sed", "consectetur", "id", "risus"}},
    {"list084", {"vestibulum", "ante", "ipsum", "primis", "in", "faucibus", "orci", "luctus", "et", "ultrices"}},
    {"list085", {"vivamus", "vestibulum", "leo", "vitae", "lorem", "tincidunt", "nec", "gravida", "neque", "vehicula"}},
    {"list086", {"donec", "mollis", "urna", "lectus", "praesent", "ornare", "arcu", "convallis", "lacus", "tempus"}},
    {"list087", {"nam", "laoreet", "nibh", "vel", "pretium", "vestibulum", "cras", "finibus", "eget", "eros"}},
    {"list088", {"integer", "pulvinar", "nunc", "nec", "orci", "accumsan", "venenatis", "maecenas", "quam", "est"}},
    {"list089", {"ut", "aliquet", "risus", "vel", "dapibus", "tristique", "fusce", "rutrum", "risus", "cursus"}},
    {"list090",
     {"suspendisse", "ac", "ullamcorper", "justo", "morbi", "vel", "dolor", "condimentum", "viverra", "ligula"}},
    {"list091", {"phasellus", "vestibulum", "elit", "et", "dictum", "rutrum", "velit", "odio", "mattis", "odio"}},
    {"list092", {"curabitur", "nunc", "diam", "pellentesque", "sed", "ultrices", "et", "varius", "non", "lacus"}},
    {"list093",
     {"aliquam", "consectetur", "elementum", "felis", "sed", "hendrerit", "massa", "consectetur", "sagittis", "nunc"}},
    {"list094", {"in", "hac", "habitasse", "platea", "dictumst", "integer", "hendrerit", "lorem", "nec", "auctor"}},
    {"list095", {"pellentesque", "dictum", "mattis", "mattis", "donec", "nec", "commodo", "nibh", "in", "imperdiet"}},
    {"list096", {"mauris", "eget", "urna", "vulputate", "iaculis", "tellus", "pharetra", "laoreet", "justo", "proin"}},
    {"list097",
     {"nam", "tincidunt", "tortor", "eu", "scelerisque", "convallis", "erat", "magna", "consectetur", "enim"}},
    {"list098", {"aenean", "posuere", "ante", "vitae", "lobortis", "fringilla", "magna", "lorem", "volutpat", "dui"}},
    {"list099",
     {"suspendisse", "mattis", "arcu", "ut", "ipsum", "cursus", "vestibulum", "interdum", "et", "malesuada"}},
    {"list100", {"aenean", "pharetra", "leo", "sem", "non", "pretium", "nibh", "faucibus", "id", "duis"}},
    {"list101", {"lorem", "ipsum", "dolor", "sit", "amet", "consectetur", "adipiscing", "elit", "aliquam", "accumsan"}},
    {"list102", {"donec", "in", "egestas", "diam", "aenean", "suscipit", "scelerisque", "efficitur", "integer", "a"}},
    {"list103", {"maecenas", "metus", "erat", "vestibulum", "quis", "porta", "in", "consequat", "sed", "justo"}},
    {"list104", {"aliquam", "erat", "volutpat", "integer", "laoreet", "tellus", "ut", "nibh", "viverra", "in"}},
    {"list105", {"integer", "eu", "velit", "ac", "erat", "fringilla", "ullamcorper", "id", "in", "tortor"}},
    {"list106", {"quisque", "at", "dapibus", "ante", "donec", "et", "lectus", "sit", "amet", "lorem"}},
    {"list107",
     {"curabitur", "imperdiet", "nibh", "sit", "amet", "pellentesque", "tincidunt", "quisque", "ornare", "enim"}},
    {"list108",
     {"aliquam", "vitae", "condimentum", "libero", "non", "sodales", "metus", "vestibulum", "aliquet", "ullamcorper"}},
    {"list109", {"pellentesque", "sed", "diam", "tellus", "donec", "sed", "nulla", "lorem", "sed", "imperdiet"}},
    {"list110", {"nam", "sagittis", "maximus", "congue", "class", "aptent", "taciti", "sociosqu", "ad", "litora"}},
    {"list111",
     {"praesent", "semper", "elit", "ut", "consequat", "fringilla", "mauris", "turpis", "volutpat", "risus"}},
    {"list112", {"nullam", "risus", "urna", "facilisis", "sit", "amet", "nibh", "id", "blandit", "mollis"}},
    {"list113", {"donec", "non", "ante", "nisi", "praesent", "suscipit", "erat", "quis", "lorem", "convallis"}},
    {"list114",
     {"maecenas", "tincidunt", "suscipit", "ipsum", "non", "tristique", "proin", "accumsan", "cursus", "justo"}},
    {"list115", {"nulla", "facilisi", "nullam", "et", "enim", "finibus", "aliquet", "mi", "ut", "mattis"}},
    {"list116", {"fusce", "rutrum", "lobortis", "ligula", "vitae", "condimentum", "risus", "ultrices", "sed", "sed"}},
    {"list117", {"nullam", "quis", "tristique", "ante", "proin", "neque", "ante", "sollicitudin", "non", "bibendum"}},
    {"list118", {"nam", "bibendum", "quam", "et", "semper", "eleifend", "donec", "placerat", "scelerisque", "mi"}},
    {"list119", {"donec", "vel", "suscipit", "turpis", "cras", "semper", "arcu", "in", "velit", "hendrerit"}},
    {"list120",
     {"praesent", "congue", "gravida", "mauris", "integer", "ornare", "dictum", "lorem", "non", "consequat"}},
    {"list121", {"nam", "tincidunt", "tortor", "sit", "amet", "gravida", "dapibus", "fusce", "laoreet", "nulla"}},
    {"list122", {"in", "id", "enim", "pellentesque", "suscipit", "velit", "id", "posuere", "metus", "quisque"}},
    {"list123", {"curabitur", "elit", "ex", "aliquam", "eget", "mi", "sed", "tristique", "scelerisque", "ligula"}},
    {"list124", {"vivamus", "dui", "lacus", "hendrerit", "eu", "sagittis", "non", "finibus", "consequat", "turpis"}},
    {"list125", {"etiam", "ultrices", "vel", "massa", "non", "vehicula", "duis", "aliquet", "massa", "id"}},
    {"list126", {"duis", "ultrices", "sem", "a", "sapien", "dignissim", "hendrerit", "eu", "vel", "sem"}},
    {"list127", {"vivamus", "eu", "elit", "ac", "metus", "pharetra", "pretium", "etiam", "mattis", "velit"}},
    {"list128", {"ut", "ac", "commodo", "risus", "nam", "eget", "hendrerit", "magna", "vestibulum", "elementum"}},
    {"list129", {"mauris", "in", "ultricies", "tellus", "ut", "in", "velit", "porttitor", "vulputate", "enim"}},
    {"list130", {"donec", "dapibus", "urna", "ac", "scelerisque", "mollis", "urna", "orci", "congue", "nulla"}},
    {"list131", {"vivamus", "eleifend", "dapibus", "maximus", "donec", "eu", "accumsan", "nulla", "eu", "iaculis"}},
    {"list132", {"aliquam", "erat", "volutpat", "orci", "varius", "natoque", "penatibus", "et", "magnis", "dis"}},
    {"list133", {"maecenas", "laoreet", "sed", "quam", "eget", "bibendum", "etiam", "et", "sollicitudin", "mi"}},
    {"list134", {"aliquam", "rhoncus", "purus", "vel", "nibh", "laoreet", "pharetra", "vestibulum", "ante", "ipsum"}},
    {"list135", {"quisque", "semper", "urna", "vel", "mollis", "gravida", "fusce", "nibh", "mauris", "porttitor"}},
    {"list136", {"sed", "luctus", "risus", "et", "sodales", "mollis", "maecenas", "a", "tincidunt", "risus"}},
    {"list137", {"in", "hac", "habitasse", "platea", "dictumst", "nullam", "fermentum", "commodo", "tempor", "aenean"}},
    {"list138", {"nunc", "rhoncus", "diam", "magna", "ac", "lacinia", "felis", "consequat", "non", "maecenas"}},
    {"list139", {"sed", "scelerisque", "velit", "est", "sed", "mollis", "ligula", "cursus", "sed", "aliquam"}},
    {"list140", {"nulla", "dictum", "arcu", "eu", "mauris", "malesuada", "quis", "cursus", "nisi", "faucibus"}},
    {"list141",
     {"phasellus", "posuere", "lacus", "nec", "molestie", "accumsan", "metus", "tortor", "facilisis", "nunc"}},
    {"list142", {"curabitur", "ex", "neque", "pretium", "sit", "amet", "leo", "in", "tempus", "vestibulum"}},
    {"list143", {"curabitur", "tortor", "tortor", "fermentum", "eget", "velit", "ac", "cursus", "faucibus", "odio"}},
    {"list144", {"aenean", "varius", "malesuada", "sapien", "sed", "hendrerit", "purus", "molestie", "sed", "sed"}},
    {"list145", {"nam", "hendrerit", "pretium", "purus", "id", "fermentum", "nunc", "in", "lacus", "metus"}},
    {"list146", {"fusce", "euismod", "libero", "sed", "diam", "pharetra", "non", "semper", "elit", "accumsan"}},
    {"list147", {"phasellus", "sed", "ligula", "sit", "amet", "justo", "vestibulum", "fermentum", "congue", "sed"}},
    {"list148", {"sed", "dignissim", "felis", "eget", "elit", "dictum", "malesuada", "vivamus", "maximus", "mi"}},
    {"list149", {"proin", "lobortis", "tempus", "molestie", "sed", "tortor", "ipsum", "finibus", "non", "aliquet"}},
    {"list150", {"integer", "ut", "leo", "dui", "proin", "condimentum", "dolor", "a", "suscipit", "maximus"}},
    {"list151", {"vivamus", "sapien", "neque", "dapibus", "sed", "volutpat", "at", "vestibulum", "sit", "amet"}},
    {"list152", {"curabitur", "enim", "enim", "faucibus", "sit", "amet", "luctus", "aliquam", "placerat", "nec"}},
    {"list153", {"suspendisse", "ligula", "dolor", "ultricies", "sit", "amet", "iaculis", "vel", "luctus", "sit"}},
    {"list154", {"aenean", "aliquam", "elit", "sit", "amet", "ultricies", "lobortis", "nullam", "porttitor", "libero"}},
    {"list155",
     {"ut", "tincidunt", "convallis", "placerat", "suspendisse", "potenti", "cras", "commodo", "fringilla", "lacus"}},
    {"list156", {"nulla", "quis", "elit", "est", "etiam", "sagittis", "molestie", "porta", "lorem", "ipsum"}},
    {"list157", {"in", "turpis", "nibh", "gravida", "vitae", "ex", "eu", "eleifend", "tincidunt", "neque"}},
    {"list158", {"suspendisse", "in", "fermentum", "orci", "etiam", "viverra", "metus", "a", "condimentum", "blandit"}},
    {"list159", {"fusce", "dapibus", "velit", "id", "est", "maximus", "rhoncus", "quisque", "lobortis", "tortor"}},
    {"list160", {"ut", "molestie", "ornare", "velit", "id", "consectetur", "nunc", "varius", "eu", "vivamus"}},
    {"list161", {"aenean", "egestas", "nibh", "at", "tincidunt", "varius", "felis", "metus", "ullamcorper", "purus"}},
    {"list162", {"donec", "a", "eleifend", "libero", "sed", "fermentum", "sem", "fusce", "eget", "lacinia"}},
    {"list163", {"nullam", "metus", "mauris", "ornare", "in", "sem", "at", "posuere", "placerat", "nisl"}},
    {"list164", {"maecenas", "vitae", "enim", "ipsum", "sed", "mattis", "porta", "mi", "congue", "suscipit"}},
    {"list165", {"nulla", "placerat", "porttitor", "metus", "non", "suscipit", "turpis", "rhoncus", "non", "etiam"}},
    {"list166", {"morbi", "id", "fringilla", "quam", "eget", "sollicitudin", "felis", "aliquam", "quis", "risus"}},
    {"list167",
     {"pellentesque", "maximus", "leo", "ut", "quam", "consequat", "lacinia", "suspendisse", "facilisis", "leo"}},
    {"list168", {"phasellus", "rhoncus", "urna", "felis", "nullam", "pharetra", "porttitor", "neque", "sit", "amet"}},
    {"list169", {"in", "posuere", "mauris", "sit", "amet", "nisl", "tempor", "eget", "euismod", "neque"}},
    {"list170",
     {"mauris", "id", "lobortis", "magna", "suspendisse", "nisl", "orci", "auctor", "suscipit", "malesuada"}},
    {"list171", {"ut", "facilisis", "magna", "vitae", "ligula", "laoreet", "tempor", "class", "aptent", "taciti"}},
    {"list172", {"aenean", "sagittis", "lacus", "vel", "nulla", "porta", "quis", "egestas", "sem", "ullamcorper"}},
    {"list173", {"donec", "eget", "purus", "scelerisque", "rutrum", "dolor", "eget", "maximus", "dui", "aliquam"}},
    {"list174", {"donec", "congue", "a", "massa", "vel", "posuere", "donec", "ullamcorper", "elit", "id"}},
    {"list175", {"praesent", "consectetur", "est", "eu", "tellus", "dictum", "tempor", "nullam", "id", "risus"}},
    {"list176", {"etiam", "gravida", "gravida", "tempus", "fusce", "lobortis", "orci", "ac", "volutpat", "mollis"}},
    {"list177", {"quisque", "quis", "turpis", "et", "augue", "dignissim", "maximus", "donec", "vel", "justo"}},
    {"list178", {"aenean", "consectetur", "mi", "non", "nibh", "bibendum", "ac", "tincidunt", "dui", "tristique"}},
    {"list179", {"aliquam", "tempus", "elit", "non", "ipsum", "finibus", "ut", "luctus", "dolor", "tincidunt"}},
    {"list180", {"donec", "eget", "ultricies", "tellus", "et", "imperdiet", "tellus", "vivamus", "maximus", "massa"}},
    {"list181",
     {"pellentesque", "eget", "volutpat", "velit", "eu", "venenatis", "mi", "suspendisse", "fringilla", "dignissim"}},
    {"list182", {"maecenas", "auctor", "leo", "sed", "sapien", "vehicula", "nec", "porttitor", "ante", "porta"}},
    {"list183", {"nulla", "risus", "lectus", "interdum", "rutrum", "aliquam", "sed", "consectetur", "id", "risus"}},
    {"list184", {"vestibulum", "ante", "ipsum", "primis", "in", "faucibus", "orci", "luctus", "et", "ultrices"}},
    {"list185", {"vivamus", "vestibulum", "leo", "vitae", "lorem", "tincidunt", "nec", "gravida", "neque", "vehicula"}},
    {"list186", {"donec", "mollis", "urna", "lectus", "praesent", "ornare", "arcu", "convallis", "lacus", "tempus"}},
    {"list187", {"nam", "laoreet", "nibh", "vel", "pretium", "vestibulum", "cras", "finibus", "eget", "eros"}},
    {"list188", {"integer", "pulvinar", "nunc", "nec", "orci", "accumsan", "venenatis", "maecenas", "quam", "est"}},
    {"list189", {"ut", "aliquet", "risus", "vel", "dapibus", "tristique", "fusce", "rutrum", "risus", "cursus"}},
    {"list190",
     {"suspendisse", "ac", "ullamcorper", "justo", "morbi", "vel", "dolor", "condimentum", "viverra", "ligula"}},
    {"list191", {"phasellus", "vestibulum", "elit", "et", "dictum", "rutrum", "velit", "odio", "mattis", "odio"}},
    {"list192", {"curabitur", "nunc", "diam", "pellentesque", "sed", "ultrices", "et", "varius", "non", "lacus"}},
    {"list193",
     {"aliquam", "consectetur", "elementum", "felis", "sed", "hendrerit", "massa", "consectetur", "sagittis", "nunc"}},
    {"list194", {"in", "hac", "habitasse", "platea", "dictumst", "integer", "hendrerit", "lorem", "nec", "auctor"}},
    {"list195", {"pellentesque", "dictum", "mattis", "mattis", "donec", "nec", "commodo", "nibh", "in", "imperdiet"}},
    {"list196", {"mauris", "eget", "urna", "vulputate", "iaculis", "tellus", "pharetra", "laoreet", "justo", "proin"}},
    {"list197",
     {"nam", "tincidunt", "tortor", "eu", "scelerisque", "convallis", "erat", "magna", "consectetur", "enim"}},
    {"list198", {"aenean", "posuere", "ante", "vitae", "lobortis", "fringilla", "magna", "lorem", "volutpat", "dui"}},
    {"list199",
     {"suspendisse", "mattis", "arcu", "ut", "ipsum", "cursus", "vestibulum", "interdum", "et", "malesuada"}},
    {"list200", {"aenean", "pharetra", "leo", "sem", "non", "pretium", "nibh", "faucibus", "id", "duis"}}};

std::string string_template {
    "Lorem {{ name }}! {% for v1 in list001 %}{{ v1 }} {% for v2 in list002 %}{{ v2 }} {% for v3 in list003 %}{{ v1 }} "
    "{{ v3 }} {{name}}\n{% endfor %}{% endfor %}{% endfor %}Omnis in aut nobis libero enim. Porro optio ratione "
    "molestiae necessitatibus numquam architecto soluta. Magnam minus unde quas {{ name }} aspernatur occaecati et "
    "voluptas cupiditate. Assumenda ut alias quam voluptate aut saepe ullam dignissimos. \n Sequi aut autem nihil "
    "voluptatem tenetur incidunt. Autem commodi animi rerum. {{ lower(name) }} Mollitia eligendi aut sed rerum veniam. "
    "Eum et fugit velit sint ratione voluptatem aliquam. Minima sint consectetur natus modi quis. Animi est nesciunt "
    "cupiditate nostrum iure. Voluptatem accusamus vel corporis. \n Debitis {{ name }} sunt est debitis distinctio ut. "
    "Provident corrupti nihil velit aut tempora corporis corrupti exercitationem. Praesentium cumque ex est itaque."};

BENCHMARK(InjaBenchmarkerSmallData, render, 5, 50) { env.render(string_template, smallData); }

BENCHMARK(InjaBenchmarkerLargeData, render, 5, 25) { env.render(string_template, largeData); }

int main() {
  hayai::ConsoleOutputter consoleOutputter;

  hayai::Benchmarker::AddOutputter(consoleOutputter);
  hayai::Benchmarker::RunAllTests();
  return 0;
}
